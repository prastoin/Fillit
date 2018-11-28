/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 13:01:24 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static int			ft_error(char **tab)
{
	charfree(tab);
	ft_putstr("error\n");
	return (-1);
}

static int			ft_error1(void)
{
	ft_putstr("error\n");
	return (-1);
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
