/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcazier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:11:59 by fcazier           #+#    #+#             */
/*   Updated: 2018/12/07 15:43:40 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		first_pos_y(t_tris tetris)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris.content[y][x] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int		first_pos_x(t_tris tetris)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris.content[y][x] == '#')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

char		**pos_tetri(t_tris tetris, int ybase, int xbase)
{
	char **tab;
	int x;
	int y;

	x = 0;
	y = 0;
	tab[0][0] = 'A';
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris.content[y][x] == '#')
				tab[ybase - y][xbase - x] = 'A';
			x++;
		}
		y++;
	}
	return (tab);
}
