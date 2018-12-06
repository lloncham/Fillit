/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:57:50 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/06 16:44:13 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_tetri(t_tris *tabtetris, int fd)
{
	char	buff[22];
	int		ret;
	int		i;

	i = 0;
	while (((ret = read(fd, buff, 21)) > 0))
	{
		buff[ret] = '\0';
		if (isvalid(buff, ret) != 0)
			return (0);
		tabtetris[i] = new_tetri(buff, ret);
		printf("%s\n", tabtetris[i].content[0]);
		i++;
	}
	return (i);
}

t_tris		new_tetri(char *buff, int len)
{
	t_tris tetris;
	int i;

	i = 0;
	while (i < len)
	{
		if (i % 5 < 4)
			tetris.content[i / 5][i % 5] = *(buff + i);
		else
			tetris.content[i / 5][i % 5] = '\0';
		i++;
	}
	return (tetris);
}
