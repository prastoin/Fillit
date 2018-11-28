/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:35:09 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 14:28:36 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int nbtetri)
{
	char		**map;
	static int	c;
	int			i;
	int			j;

	if (!(c))
		c = ft_sqrt_close(nbtetri * 4);
	else
		c++;
	if (!(map = (char **)malloc(sizeof(char *) * c + 1)))
		return (NULL);
	i = 0;
	while (i < c)
	{
		j = 0;
		if (!(map[i] = (char *)malloc(sizeof(char) * c + 1)))
			return (NULL);
		while (j < c)
			map[i][j++] = '.';
		map[i][c] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
