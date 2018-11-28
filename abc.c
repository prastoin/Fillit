/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:27:40 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 13:44:58 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			abc(char *str)
{
	int				i;
	static	char	a;
	static int		count;

	i = 0;
	if (!(a))
		a = 'A';
	if (count != 4)
	{
		if (a >= 'Z' + 1)
			return (-1);
		while (str[i] != '\0')
		{
			if (str[i] == '#')
				str[i] = a;
			i++;
		}
	}
	if (count == 4)
	{
		count = -1;
		a++;
	}
	count++;
	return (1);
}

static int	mlink(char const **tab, int y, int x, int i)
{
	int		occ;

	occ = 0;
	if ((x + 1) != 4 && ft_isupper(tab[y][x + 1]) == 1)
		occ++;
	if ((x - 1) != -1 && ft_isupper(tab[y][x - 1]) == 1)
		occ++;
	if ((i + 1) != 4 && ft_isupper(tab[y + 1][x]) == 1)
		occ++;
	if ((i - 1) != -1 && ft_isupper(tab[y - 1][x]) == 1)
		occ++;
	return (occ);
}

int			valid(char const **tab)
{
	static int	y;
	int			xoctpi[4];

	xoctpi[3] = 0;
	xoctpi[1] = 0;
	xoctpi[2] = 0;
	while (tab[y] != NULL && tab[y][0] != '\0')
	{
		xoctpi[0] = 0;
		while(tab[y][xoctpi[0]] != '\0' && tab[y] != NULL)
		{
			if (ft_isupper(tab[y][xoctpi[0]]) == 1)
			{
				xoctpi[2] = mlink(tab, y, xoctpi[0], xoctpi[3]);
				xoctpi[1] += xoctpi[2];
			}
			xoctpi[0]++;
		}
		xoctpi[3]++;
		y++;
	}
	if (xoctpi[1] < 6)
		return (-1);
	y++;
	return (1);
}
