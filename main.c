/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:29:21 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/18 13:07:31 by lloncham         ###   ########.fr       */
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

int		create_tab(char **map, int size)
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
			ft_putchar(map[y][x]);
			x++;
		}
		map[y][x] = '\0';
		ft_putchar('\n');
		y++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int fd;
	int size;
	char **map;
	t_tris tabtetris[27];

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = min_map(read_tetri(tabtetris, fd) * 4);
//	if (!read_tetri(tabtetris, fd))
//		return (0);
//	if (!create_tab(map, size))
//	{
//		write(1, "Error\n", 6);
//		return (0);
//	}
	create_tab(map, size);
//	ft_print_words_tables(map,'\n');
	close(fd);
	return (0);
}
