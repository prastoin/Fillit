/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:36:07 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/28 16:12:58 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*pos_min(char **sqr)
{
	int	i;
	int	j;
	int	*min;

	i = -1;
	if (!(min = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	min[0] = 4;
	min[1] = 4;
	while (++i < 4)
	{
		j = 0;
		while (j < min[1])
		{
			if (sqr[i][j] != '.')
			{
				min[0] = min[0] < i ? min[0] : i;
				min[1] = min[1] < j ? min[0] : j;
				break ;
			}
			j++;
		}
	}
	return (min);
}

static int	retour(int **min)
{
	free(*min);
	*min = NULL;
	return (1);
}

static int	mv_piece(char **sqr)
{
	int	i;
	int	j;
	int	*min;

	if ((min = pos_min(sqr)) == NULL)
		return (-1);
	if (!(min[0]) && !(min[1]))
		return (retour(&min));
	i = min[0];
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sqr[i][j] != '.')
			{
				sqr[i - min[0]][j - min[1]] = sqr[i][j];
				sqr[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	free(min);
	return (1);
}

int			move_all(char **tab, int nb)
{
	int k;

	k = 0;
	while (k < nb)
	{
		if ((mv_piece(tab + 4 * k + k)) == -1)
			return (-1);
		k++;
	}
	return (1);
}

t_struct	str_to_struc(char **sqr)
{
	int			i;
	int			j;
	int			bloc;
	t_struct	piece;

	bloc = 0;
	piece.c = '\0';
	i = -1;
	piece.posx = -1;
	piece.posy = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (sqr[i][j] != '.')
			{
				piece.c = sqr[i][j];
				piece.tetx[bloc] = j;
				piece.tety[bloc] = i;
				bloc++;
			}
		}
	}
	return (piece);
}
