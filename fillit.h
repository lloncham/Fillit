/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:28:36 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/05 18:08:57 by lloncham         ###   ########.fr       */
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
	char			content[4][4];
	int				x;
	int				y;

}					t_tris;

int					isvalid(char *str);
void				new_tetri(t_tris tetris, char *buff);
int					read_tetri(t_tris *tetris, int fd);

#endif
