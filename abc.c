/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:27:40 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/22 11:49:59 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		abc(char **str, int count)
{
	int				i;
	static	char	*a;
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
		count = 0;
		a++;
	}
	count++;
	return (1);
}
