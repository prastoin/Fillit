/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/22 11:50:08 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	filltab(char **tab, char *line, size_t i)
{
	if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1)))
		return (NULL);
	tab[i] = line;
	return ();
}

void	ft_error(void)
{
	ft_putstr("error\n");
}

int main(int argc, const char *argv[])
{
	int		tet;
	char	*line;
	size_t	i;
	int		fd;
	char	**tab;

	if (!(tab = ((char **)malloc(sizeof(char *) * 130))))
		return (ft_error());
	fd = open(argv[1], O_READONLY);
	i = 0;
	while ((tet = get_next_line(fd,&line) > 0))
	{
		if (verif1(line, i) == -1)
			return (ft_error());
		if (abc(&line) == -1)
			return (ft_error());
		if (!(filltab(tab, line, i)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	if (verif2(tab, i) == -1)
		return (ft_error());
	return (0);
}
