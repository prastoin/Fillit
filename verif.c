/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:56:11 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/22 11:51:04 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		vtetri(const char *line, int diez)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
		return (-1);
	if (ft_strlen(line) != 4)
		return (-1);
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		if (line[i] == '#')
			diez++;
		i++;
	}
	return (diez);
}

int		verif1(const char *line, size_t nline)
{
	static	int	count;
	static	int	diez;
	static	int	tetri;
	int			tmp;

	if (count != 4)
	{
		if ((tmp = tetri(line, diez)) == -1)
			return (-1);
		diez = diez + tmp;
	}
	else
	{
		if (line[0] != '\0')
			return (-1);
	}
	if (count == 4)
	{
		tetri++;
		count = 0;
		if (diez != 4)
			return (-1);
		else
			diez = 0;
	}
	if (tetri > 26)
		return (-1);
	count++;
	return (1);
}

static int		vdiez2(char const **tab, int y, int x)
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
		else
			return (-1);
	}
}

static int		vdiez(char const **tab, int y, int x)
{
	if (x == 0 || y == 0)
		return (vdiez2(tab, y, x) == -1);
	if (ft_isupper(tab[y][x - 1]) != 0 || ft_isupper(tab[y][x + 1]) != 0
		|| ft_isupper(tab[y - 1][x]) != 0 || ft_isupper(tab[y + 1][x]) != 0)
		return (1);
	else
		return (-1);
}

int		verif2(const char **tab, size_t nline)
{
	int		y;
	int		x;
	int		i;
	int		j;

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (tab[y] != '\0')
	{
		while(tab[y][x] != '\0')
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
