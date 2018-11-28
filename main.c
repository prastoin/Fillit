/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 16:14:10 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		charfree(char **tab)
{
	int	i;

	i = 0;
	if (tab[i] != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	if (tab != NULL)
	{
		free(tab);
		tab = NULL;
	}
}

static int	ft_error(char **tab)
{
	charfree(tab);
	ft_putstr("error\n");
	return (-1);
}

static int	ft_error2(char **tab, char **map)
{
	charfree(tab);
	charfree(map);
	ft_putstr("error\n");
	return (-1);
}

static int	ft_error1(void)
{
	ft_putstr("error\n");
	return (-1);
}

int			main(int argc, const char *argv[])
{
	char	**tab;
	int		nb;
	char	**map;

	tab = NULL;
	if (argc != 2)
		return (ft_error1());
	if ((tab = ft_reading(argv, tab)) == NULL)
		return (ft_error1());
	if ((nb = ft_reading_next(tab)) == -1)
		return (ft_error(tab));
	if ((move_all(tab, nb)) == -1)
		return (ft_error(tab));
	if ((map = solver(tab, nb)) == NULL)
		return (ft_error2(tab, map));
	display_map(map);
	charfree(map);
	charfree(tab);
	return (0);
}
