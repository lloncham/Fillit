/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:23:31 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/19 17:25:20 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_place(char **map, t_tris tetris, int *fpos, int size)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		printf("y: %d - x: %d\n", fpos[1] + tetris.content[j][1], fpos[0] + tetris.content[j][0]);
		if ((fpos[1] + tetris.content[j][1]) && (fpos[0] + tetris.content[j][0] < 0))
			return (0);
		if ((fpos[1] + tetris.content[j][1]) > size && (fpos[0] + tetris.content[j][0]) > size)
			return (0);
		if (map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] != '.')
			return (-1);
		j++;
	}
	return (1);
}

int		ft_place(char **map, t_tris tetris, int *fpos, char letter)
{
	int		j; 

	j = 0;
	while (j < 4)
	{
		map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] = letter;
		j++;
	}
	return (1);
}

int		put_tetris(t_tris tabtetris[], char **map, int size, int nbt)
{
	int		fpos[2];
	char	letter;
	int		j;

	j = 1;
	letter = 'A';
	fpos[0] = 0;
	fpos[1] = 0;
	while (j <= nbt)
	{
		if ((ft_can_place(map, *tabtetris, fpos, size)) == 1)
		{
			ft_place(map, *tabtetris, fpos, letter);
			j++;
			letter += 1;
		}
		if ((ft_can_place(map, *tabtetris, fpos, size)) < 1)
		{
			if (fpos[0] <= size)
				fpos[0]++;
			if (fpos[0] == size && fpos[1] <= size)
			{
				fpos[0] = 0;
				fpos[1]++;
			}
			if (fpos[0] == size && fpos[1] == size)
				return(0);
		}
		printf("fpos[y] : %d\nfpos[x] : %d\n", fpos[1], fpos[0]);
		tabtetris++;
	}
	return (1);
}
