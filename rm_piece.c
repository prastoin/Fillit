/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:06:19 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/25 13:50:44 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rm_piece(char **map, t_struct *piece, int bloc)
{
	int	x;
	int	y;

	if (bloc == -1)
	{
		piece->posx = 0;
		piece->posy = 0;
	}
	while (bloc > 0)
	{
		bloc--;
		x = piece->posx + piece->tetx[bloc];
		y = piece->posy + piece->tety[bloc];
		map[y][x] = '.';
	}
}

void	ft_reset_pos(t_struct *piece, int nb)
{
	int		l;
	char	**tmp;

	tmp = NULL;
	l = 0;
	while (l < nb)
	{
		rm_piece(tmp, piece + l, -1);
		l++;
	}
}
