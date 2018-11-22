/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/22 17:33:53 by prastoin         ###   ########.fr       */
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

int			main(int argc, const char *argv[])
{
	int		tet;
	char	*line;
	size_t	i;
	int		fd;
	char	**tab;

	if (argc != 2)
		return (ft_error());
	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (ft_error());
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((tet = get_next_line(fd,&line) > 0))
	{
		printf("LINE = %s\n", line);
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
	if (valid((const char **)tab) == -1)
		return (ft_error());
	int k;
	k = 0;

	while (tab[k])
	{
		printf("%s\n", tab[k]);
		k++;
	}
	return (0);
}
