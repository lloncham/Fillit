/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcazier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:11:59 by fcazier           #+#    #+#             */
/*   Updated: 2018/12/06 15:12:30 by fcazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		pos_x_y(t_tris tetris)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y <= 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris.content[y][x] == '#')
			{
				tetris.x = x;
				tetris.y = y;
				break;
			}
			x++;
		}
		y++;
	}
}
