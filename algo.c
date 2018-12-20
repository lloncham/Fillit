/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:23:31 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 11:27:04 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_place(t_tris tetris, int *fpos, int size)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((fpos[1] + tetris.content[j][1]) > 0 && (fpos[0] + tetris.content[j][0] < 0))
			return (0);
		if ((fpos[1] + tetris.content[j][1]) > size - 1 && (fpos[0] + tetris.content[j][0]) > size - 1)
			return (0);
		j++;
	}
	return (1);
}

int		check_point(char **map, t_tris tetris, int *fpos, int size)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] != '.')
		{
			if (fpos[0] < size - 1)
				fpos[0]++;
			if (fpos[0] == size - 1 && fpos[1] < size - 1)
			{
				fpos[1]++;
				fpos[0] = 0;
			}
			if (fpos[0] == size - 1 && fpos[1] == size - 1)
				return(0);
			printf("fpos[y] : %d - fpos[x] : %d\n", fpos[1], fpos[0]);
			check_point(map, tetris, fpos, size);
		}
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
//		printf("y: %d - x: %d\n", fpos[1] + tetris.content[j][1], fpos[0] + tetris.content[j][0]);
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
		if ((ft_can_place(*tabtetris, fpos, size)) == 1)
		{
			if (check_point(map, *tabtetris, fpos, size) == 1)
			{
				ft_place(map, *tabtetris, fpos, letter);
				j++;
				letter += 1;
				ft_print_words_tables(map, '\n');
			}
			else
				return (0);
		}
		tabtetris++;
	}
	return (1);
}
