/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:23 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/28 13:08:18 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	try_again(char **map, int *l, t_struct *piece)
{
	if (*l != 0)
		*l--;
	rm_piece(map, &piece[*l], 4);
	if (piece[*l].posx >= 0)
		piece[*l].posx++;
	if (*l < nb - 2)
		rm_piece(map, &piece[*l + 1], -1);
	*l--;
}

static int	expand_map(char **map, t_struct *piece, int *z, int *size)
{
	*z++;
	*size++;
	charfree(map);
	map = create_map(nb + z);
	ft_reset_pos(piece, nb);
	return (0);
}

char		**solver(char **tab, int nb)
{
	t_struct	piece[nb];
	int			l;
	int			size;
	int			put;
	int			z;

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
			try_again(map, &l, piece);
		l++;
		if (!(put) && piece[0].posx == -1)
			l = expand_map(map, piece, &z, &size);
	}
	return (map);
}

void		display_map(char **map)
{
	int	k;

	k = 0;
	while (map[k])
		ft_putendl(map[k++]);
}
