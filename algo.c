/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:35:09 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/27 15:00:09 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*static t_struct	fillstruct(t_struct s_tetri, int y, int x)
{
	t_struct *ptr;
	static int	i;
	static int	j;

	if (i == 4)
	{
		i = 0;
		j = 0;
	}
	ptr = s_tetri;

	ptr->tetx[i] = x;
	ptr->tety[j] = y;
	j++;
	i++;
	return (s_tetri);
}

t_struct	nextetri(char **tab, int nbtetri)
{
	t_struct s_tetri;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;

	while (y < 5)
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_isupper(tab[y][x]) == 1)
				fillstruct(s_tetri, tab, y, x);
			x++;
		}
		y++;
	}
	return (s_tetri);
}
*/
char	**create_map(int nbtetri)
{
	char	**map;
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
