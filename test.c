/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:55:18 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/24 16:59:31 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	int	i;
	int	size;

	i = 1;
	while (i <= 4)
		printf("%s\n", argv[i++]);
	i = 1;
	mv_piece(argv + 1);
	while (i <= 4)
		printf("%s\n", argv[i++]);
	size = 4;
	printf("volume :%d\n", volume_ele(argv + 1, size));
/*	i = 1;
	while (i <= 4)
		printf("%s\n", argv[i++]);*/
	return (0);
}
