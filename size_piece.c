/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:40:26 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/24 17:05:03 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		width_ele(char **sqr, int size)
{
	int	i;
	int	j;
	int	x_min;
	int	x_max;

	x_min = 5;
	x_max = -1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && sqr[i][j] != '.')
		{
			if (j < x_min)
				x_min = j;
			j++;
		}
		if (j > x_max)
			x_max = j;
		i++;
	}
	return (x_max - x_min);
}

int		height_ele(char **sqr, int size)
{
	int	i;
	int	j;
	int	y_min;
	int	y_max;

	y_min = 5;
	y_max = -1;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			while (i < size && sqr[i][j] != '.')
			{
				if (i < y_min)
					y_min = i;
				i++;
			}
			if (i > y_max && sqr[i - 1][j] != '.')
				y_max = i;
			i++;
		}
		j++;
	}
	return (y_max - y_min);
}

int		volume_ele(char **map, int size)
{
	return (width_ele(map, size) * height_ele(map, size));
}
