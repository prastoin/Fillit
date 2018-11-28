/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:23 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/28 16:12:18 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	try_again(char **map, int *l, t_struct *piece, int nb)
{
	if (*l != 0)
		*l -= 1;
	rm_piece(map, &piece[*l], 4);
	if (piece[*l].posx >= 0)
		piece[*l].posx++;
	if (*l < nb - 2)
		rm_piece(map, &piece[*l + 1], -1);
	*l -= 1;
}

static int	expand_map(char ***map, t_struct *piece, int *size, int nb)
{
	static int	z;

	z += 1;
	*size += 1;
	charfree(*map);
	if (!(*map = create_map(nb + z)))
		return (-1);
	ft_reset_pos(piece, nb);
	return (0);
}

char		**solver(char **tab, int nb)
{
	t_struct	piece[nb];
	static int	l;
	int			size;
	int			put;
	char		**map;

	while (l < nb)
		piece[l++].c = 0;
	l = 0;
	if (!(map = create_map(nb)))
		return (NULL);
	size = ft_strlen(map[0]);
	while (l < nb)
	{
		if (!ft_isupper(piece[l].c))
			piece[l] = str_to_struc(tab + 4 * l + l);
		put = put_piece(map, size, piece + l);
		if (!put)
			try_again(map, &l, piece, nb);
		l++;
		if (!(put) && piece[0].posx == -1)
			if ((l = expand_map(&map, piece, &size, nb)) == -1)
				return (NULL);
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
