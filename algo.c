/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:23:31 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/19 13:04:18 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_place(char **map, t_tris tetris, int *fpos, int size)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		printf("x: %d - y: %d\n", fpos[1] + tetris.content[j][1], fpos[0] + tetris.content[j][0]);
		if (map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] < 0)
			return (0);
		if (map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] > size)
			return (0);
		j++;
	}
	return (1);
}

int		*ft_place(char **map, t_tris tetris, int *fpos, char letter)
{
	int		j; 

	j = 0;
	while (j < 4)
	{
		printf("x: %d - y: %d", fpos[1] + tetris.content[j][1], fpos[0] + tetris.content[j][0]);
		map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] = letter;
		map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] = letter;
		j++;
	}
	fpos[1] = fpos[1] + tetris.content[j][1];
	fpos[0] = fpos[0] + tetris.content[j][0];
	return (fpos);
}

int		put_tetris(t_tris tabtetris[], char **map, int size)
{
	int		i;
	int		fpos[2];
	char	letter;

	i = 0;
	letter = 'A';
	fpos[0] = 0;
	fpos[1] = 0;
	while (tabtetris[i].empty != 1)
	{
		ft_putendl("Test");
		if (ft_can_place(map, *tabtetris, fpos, size) == 1)
			ft_place(map, *tabtetris, fpos, letter);
		letter += 1;
		i++;
	}
	return (1);
}
