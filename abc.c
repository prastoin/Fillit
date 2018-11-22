/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:27:40 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/22 17:36:47 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		abc(char *str)
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
	printf("ok\n");
	return (1);
}

int		mlink(char const **tab, int y, int x, int occ)
{
	if ((occ < 7) && (x + 1) && ft_isupper(tab[y][x + 1]) == 1)
		mlink(tab, y, ++x, ++occ);
	if ((occ < 7) && (x - 1) != -1 && ft_isupper(tab[y][x - 1]) == 1)
		mlink(tab, y, --x, ++occ);
	if ((occ < 7) && (y + 1) != 5 && ft_isupper(tab[y + 1][x]) == 1)
		mlink(tab, ++y, x, ++occ);
	if ((occ < 7) && (y - 1) != -1 && ft_isupper(tab[y - 1][x]) == 1)
		mlink(tab, --y, x, ++occ);
	printf("%d\n", occ);
	if (occ == 6)
		return (1);
	return (-1);
}

int		valid(char const **tab)
{
	static int	y;
	static int	x;
	static int	occ;

	while (tab[y])
	{
		x = 0;
		while(tab[y][x])
		{
			if (ft_isupper(tab[y][x]) == 1)
				return (mlink(tab, y, x, occ));
			x++;
		}
		y++;
	}
	return (-1);
}
