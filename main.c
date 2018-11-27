/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/27 14:57:08 by prastoin         ###   ########.fr       */
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

int			ft_error(void)
{
	ft_putstr("error\n");
	return (-1);
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

int			main(int argc, const char *argv[])
{
	int		tet;
	char	*line;
	size_t	i;
	int		fd;
	char	**tab;
	int		nb;

	if (argc != 2)
		return (ft_error());
	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (ft_error());
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((tet = get_next_line(fd,&line) > 0))
	{
		if (verif1(line) == -1)
			return (ft_error());
		if (abc(line) == -1)
			return (ft_error());
		if (!(filltab(tab, line, i)))
			return (-1);
		i++;
	}
	tab[i] = NULL;
	if ((nb = nbtetri((char const **)tab)) > 26)
		return (-1);
	if (verif2((const char **)tab) == -1)
		return (ft_error());
	while (tet < nb - 1)
	{
		if (valid((const char **)tab) == -1)
			return (ft_error());
		tet++;
	}
	int k;
	k = -1;
	printf("nb :%d\n", nb);
	while (++k < nb)
		mv_piece(tab + 4 * k + k);
	k = 0;
	while (tab[k])
	{
		printf("%s\n", tab[k]);
		k++;
	}
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
	while (map[z])
	{
		printf("%s\n", map[z]);
		z++;
	}
	size = ft_strlen(map[0]);
	while (l < nb)
	{
		if (!ft_isupper(piece[l].c))
			piece[l] = str_to_struc(tab + 4 * l + l);
		put = put_piece(map, size, piece + l);
		if (!put)
		{
	printf("map creat\n");
			if (l != 0)
				l--;
			rm_piece(map, &piece[l], 4);
			printf("x :%d\ty :%d\n", piece[l].posx, piece[l].posy);
			piece[l].posx++;
			printf("x :%d\ty :%d\n", piece[l].posx, piece[l].posy);
			k = -1;
			printf("retirer %c\n", piece[l].c);
			if (l < nb - 2)
				rm_piece(map,&piece[l + 1], -1);
			while (++k < size)
				printf("%s\n",map[k]);
			l--;
		}
		printf("\n");
		k = -1;
		while (++k < size)
			printf("%s\n",map[k]);
		l++;
		if (!(put) && l == 0)
		{
			z++;
			map = create_map(nb + z);
			printf("create map qui chie\n");
			ft_reset_pos(piece, nb);
			l = 0;
		}
	}
	return (0);
}
