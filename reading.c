/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 15:40:48 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	filltab(char **tab, char *line, size_t i)
{
	tab[i] = line;
	return (1);
}

static int	nbtetri(char const **tab)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '\0')
			count++;
		i++;
	}
	return (count);
}

static char	**ft_failreading(char **tab, int i)
{
	tab[i + 1] = NULL;
	charfree(tab);
	return (NULL);
}

char		**ft_reading(const char **argv, char **tab)
{
	int		fd;
	int		i;
	char	*line;
	int		count;

	count = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (((count = verif1(line)) == -1) || abc(line) == -1)
		{
			ft_strdel(&line);
			return (ft_failreading(tab, i));
		}
		filltab(tab, line, i);
		i++;
		tab[i] = NULL;
	}
	if (count != 4)
		return (ft_failreading(tab, i - 1));
	return (tab);
}

int			ft_reading_next(char **tab)
{
	int	nb;
	int	i;

	i = 0;
	if ((nb = nbtetri((char const **)tab)) > 26)
		return (-1);
	if (verif2((const char **)tab) == -1)
		return (-1);
	while (i < nb)
	{
		if (valid((const char **)tab) == -1)
			return (-1);
		i++;
	}
	return (nb);
}
