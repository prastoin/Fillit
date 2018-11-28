/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:27:40 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 10:43:26 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		abc(char *str)
{
	int				i;
	static	char	a;
	static int		count;

	i = 0;
	if (!(str))
		return (1);
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
		if ((a + 1) == ('Z' + 1))
			return (-1);
		a++;
	}
	count++;
	return (1);
}

int		mlink(char const **tab, int y, int x)
{
	int		occ;

	occ = 0;
	if ((x + 1) != 4 && ft_isupper(tab[y][x + 1]) == 1)
		occ++;
	if ((x - 1) != -1 && ft_isupper(tab[y][x - 1]) == 1)
		occ++;
	if ((y + 1) != 4 && ft_isupper(tab[y + 1][x]) == 1)
		occ++;;
	if ((y - 1) != -1 && ft_isupper(tab[y - 1][x]) == 1)
		occ++;
	return (occ);
}

int		valid(char const **tab)
{
	static int	y;
	int			x;
	int			occ;
	int			tmp;

	occ = 0;
	tmp = 0;
	while (tab[y][0] != '\0' && tab[y] != NULL)
	{
		x = 0;
		while(tab[y][x] != '\0')
		{
			if (ft_isupper(tab[y][x]) == 1)
			{
				tmp = mlink(tab, y, x);
				occ += tmp;
			}
			x++;
		}
		y++;
	}
	if (occ != 6)
		return (-1);
	y++;
	return (1);
}
