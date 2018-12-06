/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:57:50 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/06 15:12:34 by fcazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_tetri(t_tris *tabtetris, int fd)
{
	char	buff[22];
	int		ret;
	static int		i;
	static int		y;

	y = 0;
	i = 0;
	while (((ret = read(fd, buff, 21)) > 0))
	{
		if (isvalid(buff) != 0)
			return (-1);
		tabtetris[i] = new_tetri(tabtetris[i], buff);
		printf("%s\n", tabtetris);
		i++;
	}
	return (i);
}

static t_tris		new_tetri(t_tris tetris, char *buff)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	while (y <= 4)
	{
		x = 0;
		while (x < 4)
		{
			tetris.content[y][x] = *(buff + i);
			//printf("%c", tetris.content[y][x]);
			x++;
			i++;
		}
		y++;
	}
	return (tetris);
}
