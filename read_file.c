/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:17:42 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 16:43:21 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_tetri(t_tris *tabtetris, int fd)
{
	char	buff[22];
	int		ret;
	int		tmp;
	int		i;

	i = 0;
	while (((ret = read(fd, buff, 21)) > 0))
	{
		tmp = 0;
		buff[ret] = '\0';
		tmp = ret;
		if (isvalid(buff, ret) != 0)
			return (0);
		tabtetris[i] = new_tetri(buff, ret);
		i++;
	}
	if (tmp != 20)
		return (0);
	tabtetris[i].content[0][0] = 8;
	return (i);
}

t_tris		new_tetri(char *buff, int len)
{
	t_tris tetris;
	int 	i;
	int		j;
	int		spos[2];

	i = 0;
	j = 0;
	spos[0] = 3;
	spos[1] = 3;
	while (i < len)
	{
		if (buff[i] == '#')
		{
			if (spos[0] > i % 5)
				spos[0] = i % 5;
			if (spos[1] > i / 5)
				spos[1] = i / 5;
		}
		i++;
	}
	i = spos[1] * 5 + spos[0];
	while (i < len)
	{
		if (buff[i] == '#')
		{
			tetris.content[j][0] = (i % 5) - spos[0];
			tetris.content[j][1] = (i / 5) - spos[1];
			j++;
		}
		i++;
	}
	//printf("x: %d y: %d\n", tetris.content[3][0], tetris.content[3][1]);
	return (tetris);
}
