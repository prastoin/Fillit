/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/23 11:27:48 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	filltab(char **tab, char *line, size_t i)
{
	if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1)))
		return (0);
	tab[i] = line;
	return (1);
}

int			ft_error(void)
{
	ft_putstr("error\n");
	return (-1);
}

int		nbtetri(char const **tab)
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

int			main(int argc, const char *argv[])
{
	int		tet;
	char	*line;
	size_t	i;
	int		fd;
	char	**tab;
	int		nb;

	if (argc != 2)
		return (ft_error());
	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (ft_error());
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((tet = get_next_line(fd,&line) > 0))
	{
		if (verif1(line) == -1)
			return (ft_error());
		if (abc(line) == -1)
			return (ft_error());
		if (!(filltab(tab, line, i)))
			return (-1);
		i++;
	}
	tab[i] = NULL;
	if (verif2((const char **)tab) == -1)
		return (ft_error());
	printf("tout est ok jusaue ici\n");
	nb = nbtetri((char const **)tab);
		int k;
	k = 0;

	while (tab[k])
	{
		printf("%s\n", tab[k]);
		k++;
	}
	while (tet < nb - 1)
	{
		if (valid((const char **)tab, nb) == -1)
			return (ft_error());
		tet++;
	printf("TET %d nb %d\n", tet, nb);
	}
	printf("OK POUR TOUT\n");
	return (0);
}
