/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:28:36 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 15:02:38 by lloncham         ###   ########.fr       */
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

# include <stdio.h>

typedef struct		s_tris
{
	int			content[4][2];
}					t_tris;

int					isvalid(char *str, int len);
t_tris				new_tetri(char *buff, int len);
int					read_tetri(t_tris *tabtetris, int fd);
char				**create_tab(char **map, int size);
int					min_map(int nb);
int					ft_place(char **map, t_tris tetris, int *fpos, char letter);
int					ft_can_place(char **map, t_tris tetris, int *fpos, int size);
char				**put_tetris(t_tris *tabtetris, char **map, int size, char letter);
int					ft_remove(char **map, t_tris tetris, int *fpos);

#endif
