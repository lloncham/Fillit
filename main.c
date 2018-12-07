/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:29:21 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/07 15:04:31 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int fd;
	int x;
	int y;
	t_tris tetris;
	t_tris tabtetris[27];

	x = 0;
	if (fd == -1)
		return (-1);
	if (ac != 2)
		return (-2);
	//if (!read_tetri(tetri, fd))
	//	return (-3);
	fd = open(av[1], O_RDONLY);
	read_tetri(tabtetris, fd);
	return (0);
}
