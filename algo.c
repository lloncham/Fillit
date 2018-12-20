/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:23:31 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 16:10:27 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_place(char **map, t_tris tetris, int *fpos, int size)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((fpos[1] + tetris.content[j][1]) > 0 && (fpos[0] + tetris.content[j][0] < 0))
			return (0);
		if ((fpos[1] + tetris.content[j][1]) > size && (fpos[0] + tetris.content[j][0]) > size)
			return (0);
		if (map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] != '.')
			return (0);
		if (fpos[0] == size && fpos[1] == size)
			return(-1);
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

int		ft_remove(char **map, t_tris tetris, int *fpos)
{
	int		j; 

	j = 0;
	while (j < 4)
	{
		map[fpos[1] + tetris.content[j][1]][fpos[0] + tetris.content[j][0]] = '.';
		j++;
	}
	return (1);
}

char	**put_tetris(t_tris tabtetris[], char **map, int size, char letter)
{
	int		fpos[2];

	fpos[0] = -1;
	fpos[1] = 0;
	if (tabtetris->content[0][0] == 8)
		return (map);
	while (1)
	{
		if (fpos[0] < size)
			fpos[0]++;
		if (fpos[0] == size && fpos[1] < size)
		{
			fpos[1]++;
			fpos[0] = 0;
		}
		printf("y = %d, x = %d, res = %d, letter = %c\n", fpos[1], fpos[0], ft_can_place(map, *tabtetris, fpos, size), letter);
		if (ft_can_place(map, *tabtetris, fpos, size) == -1)
			break ;
		if (ft_can_place(map, *tabtetris, fpos, size) == 1)
		{
			ft_place(map, *tabtetris, fpos, letter);
			ft_print_words_tables(map, '\n');
			if (((map = put_tetris(tabtetris + 1, map, size, letter + 1)) != NULL))
				return (map);
			ft_remove(map, *tabtetris, fpos);
		}
	}
	return (NULL);
}
