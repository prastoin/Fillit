/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:28:08 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/28 15:50:29 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_truct
{
	int		tetx[4];
	int		tety[4];
	int		posx;
	int		posy;
	char	c;
}				t_struct;

void			charfree(char **tab);
char			**ft_reading(const char **argv, char **tab);
int				ft_reading_next(char **tab);
int				valid(const char **tab);
int				verif1(const char *line);
int				verif2(const char **tab);
int				abc(char *str);
void			rm_piece(char **map, t_struct *piece, int bloc);
int				width_ele(char **sqr, int size);
int				height_ele(char **sqr, int size);
int				volume_ele(char **map, int size);
int				move_all(char **sqr, int nb);
int				put_piece(char **map, int size, t_struct *piece);
t_struct		str_to_struc(char **sqr);
char			**create_map(int nbtetri);
int				ft_sqrt_close(int nbr);
void			ft_reset_pos(t_struct *piece, int nb);
char			**solver(char **tab, int nb);
void			display_map(char **map);

#endif
