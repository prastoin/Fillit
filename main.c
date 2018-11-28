/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 11:29:07 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	filltab(char **tab, char *line, size_t i)
{
	if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1)))
		return (0);
	tab[i] = line;
	return (1);
}

int			nbtetri(char const **tab)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '\0')
			count++;
		i++;
	}
	return (count);
}

void	charfree(char **tab)
{
	int	i;

	i = 0;
	if (tab[i] != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	if (tab != NULL)
	{
		free(tab);
		tab = NULL;
	}
}

int			ft_error(char **tab)
{
	charfree(tab);
	ft_putstr("error\n");
	return (-1);
}

int			ft_error1()
{
	ft_putstr("error\n");
	return (-1);
}

char		**ft_failreading(char **tab, int i)
{
	tab[i + 1] = NULL;
	charfree(tab);
	return(NULL);
}

char	**ft_reading(const char **argv, char **tab)
{
	int		fd;
	int		i;
	char	*line;
	int		 tet;
	int		count;

	count = 0;
	tet = 1;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (NULL);
	while ((tet = get_next_line(fd,&line)) > 0)
	{
		if ((count = verif1(line)) == -1)
			return (ft_failreading(tab, i));
		if (abc(line) == -1)
			return (ft_failreading(tab, i));
		if (!(filltab(tab, line, i)))
			return (ft_failreading(tab, i));
		i++;
		tab[i] = NULL;
	}
	if (count != 4)
		return (ft_failreading(tab, i - 1));
	return (tab);
}

int		ft_reading_next(char **tab)
{
	int	nb;
	int	i;

	i = 0;
	if ((nb = nbtetri((char const **)tab)) > 26)
		return (-1);
	if (verif2((const char **)tab) == -1)
		return (-1);
	while (i < nb - 1)
	{
		if (valid((const char **)tab) == -1)
			return (-1);
		i++;
	}
	return (nb);
}

int			main(int argc, const char *argv[])
{
	char	**tab;
	int		nb;

	tab = NULL;
	if (argc != 2)
		return (ft_error1());
	if ((tab =ft_reading(argv, tab)) == NULL)
		return (ft_error1());
	if ((nb =ft_reading_next(tab)) == -1)
		return (ft_error(tab));
	int k;
	k = -1;
	while (++k < nb)
		mv_piece(tab + 4 * k + k);
	k = 0;
	t_struct	piece[nb];
	int l;
	char	**map;
	int size;
	int	put;
	int	z;

	z = 0;
	l = 0;
	while (l < nb)
		piece[l++].c = 0;
	l = 0;
	map = create_map(nb);
	size = ft_strlen(map[0]);
	while (l < nb)
	{
		if (!ft_isupper(piece[l].c))
			piece[l] = str_to_struc(tab + 4 * l + l);
		put = put_piece(map, size, piece + l);
		if (!put)
		{
			if (l != 0)
				l--;
			rm_piece(map, &piece[l], 4);
			if (piece[l].posx >= 0)
				piece[l].posx++;
			if (l < nb - 2)
				rm_piece(map,&piece[l + 1], -1);
			l--;
		}
		k = -1;
			l++;
		if (!(put) && piece[0].posx == -1)
		{
			z++;
			size++;
			charfree(map);
			map = create_map(nb + z);
			ft_reset_pos(piece, nb);
			l = 0;
		}
	}
	while (++k < size)
		printf("%s\n",map[k]);
	charfree(map);
	charfree(tab);
	return (0);
}
