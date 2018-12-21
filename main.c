/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:29:21 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 18:10:15 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_map(int nb)
{
	int min;

	min = 1;
	if (nb == 0)
		return (0);
	while (min < 46340)
	{
		if (min * min >= nb)
			return (min);
		min++;
	}
	return (0);
}

char	**create_tab(char **map, int size)
{
	int x;
	int y;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	while (y < size)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * (size + 1))))
				return (0);
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = 0;
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	int		size;
	int		nbt;
	char	**map;
	t_tris	tabtetris[27];

	map = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if ((nbt = read_tetri(tabtetris, fd)) <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	size = min_map(nbt * 4);
	while (map == NULL)
	{
		if (!(map = create_tab(map, size - 1)))
		{
			ft_putendl("error");
			return (0);
		}
		if ((map = put_tetris(tabtetris, map, size, 'A')) == NULL)
			free(map);
		size++;
	}
	ft_print_words_tables(map,'\n');
	close(fd);
	return (0);
}
