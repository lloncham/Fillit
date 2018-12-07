/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:28:36 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/07 15:50:41 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct		s_tris
{
	int			content[4][2];

}					t_tris;

int					isvalid(char *str, int len);
t_tris				new_tetri(char *buff, int len);
int					read_tetri(t_tris *tabtetris, int fd);
int					first_pos_y(t_tris tetris);
int					first_pos_x(t_tris tetris);
char				**pos_tetri(t_tris tetris, int ybase, int xbase);

#endif
