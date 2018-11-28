/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:09:30 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/28 08:07:21 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
static int	fiil_if_empty(char **map, int size, t_struct *piece)
{
	int	bloc;
	int x;
	int y;

	bloc = 0;
	while (bloc < 4)
	{
		x = piece->posx + piece->tetx[bloc];
		y = piece->posy + piece->tety[bloc];
		if (x >= size || y >= size  || map[y][x] != '.')
		{
			rm_piece(map, piece, bloc);
			return (0);
		}
		map[y][x] = piece ->c;
		bloc++;
	}
	return (1);
}

int		put_piece(char **map, int size, t_struct *piece)
{
	int bloc;
	int	put;

	bloc = 0;
	put = 0;
	if (piece->posx == -1)
	{
		piece->posx = 0;
		piece->posy = 0;
	}
	while (!put && piece->posy < size)
	{
		while (!put && piece->posx < size)
		{
			if ((put = fiil_if_empty(map, size, piece)))
				return (put);
			piece->posx++;
		}
		piece->posy++;
		piece->posx = 0;
	}
	piece->posx = -1;
	piece->posy = -1;
	return (put);
}
