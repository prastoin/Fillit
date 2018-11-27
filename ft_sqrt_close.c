/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:50:57 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/25 14:14:43 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		test_sqrt(int nbr, long int i, int *ptr)
{
	if ((i * i) < nbr)
		test_sqrt(nbr, i + 1, ptr);
	else
	{
		if ((i * i) >= nbr)
			*ptr = i;
	}
}

int				ft_sqrt_close(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (1);
	if (nb == 2)
		return (1);
	test_sqrt(nb, i, &i);
	return (i);
}
