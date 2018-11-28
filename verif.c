/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:56:11 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 11:57:56 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	vtetri(const char *line)
{
	int		i;
	int		diez;
	int		len;

	diez = 0;
	i = 0;
	if ((len = ft_strlen(line)) != 4)
		return (-1);
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		if (line[i] == '#')
			diez++;
		i++;
	}
	return (diez);
}

int			verif1(const char *line)
{
	static	int	count;
	static	int	diez;
	int			tmp;

	tmp = 0;
	if (count <= 3)
	{
		if ((tmp = vtetri(line)) == -1)
			return (-1);
		diez += tmp;
	}
	else
	{
		count = -1;
		if (line[0] != '\0')
			return (-1);
	}
	if (count == 3)
	{
		if (diez != 4)
			return (-1);
		else
			diez = 0;
	}
	return (++count);
}

static int	vdiez2(char const **tab, int y, int x)
{
	if (x == 0 && y == 0)
	{
		if (ft_isupper(tab[y][x + 1]) != 0 || ft_isupper(tab[y + 1][x]) != 0)
			return (1);
		else
			return (-1);
	}
	if (y == 0)
	{
		if (ft_isupper(tab[y][x - 1]) != 0 || ft_isupper(tab[y][x + 1]) != 0
		|| ft_isupper(tab[y + 1][x]) != 0)
			return (1);
		else
			return (-1);
	}
	if (x == 0)
	{
		if (ft_isupper(tab[y][x + 1]) != 0 || ft_isupper(tab[y - 1][x]) != 0
		|| ft_isupper(tab[y + 1][x]) != 0)
			return (1);
	}
	return (-1);
}

static int	vdiez(char const **tab, int y, int x)
{
	if (x == 0 || y == 0)
		return (vdiez2(tab, y, x) == -1);
	if (ft_isupper(tab[y][x - 1]) != 0 || ft_isupper(tab[y][x + 1]) != 0
		|| ft_isupper(tab[y - 1][x]) != 0 || ft_isupper(tab[y + 1][x]) != 0)
		return (1);
	else
		return (-1);
}

int			verif2(const char **tab)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (tab[y] != '\0')
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (ft_isupper(tab[y][x]) != 0)
			{
				if (vdiez(tab, y, x) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (1);
}
