/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_FILE.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:20 by lloncham          #+#    #+#             */
/*   Updated: 2019/01/07 13:09:22 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		goodchar(char *str, int len)
{
	int i;
	int point;
	int hash;

	i = -1;
	point = 0;
	hash = 0;
	while (i++ < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '.')
				point++;
			if (str[i] == '#')
				hash++;
		}
		else if (str[i] != '\n')
			return (-1);
	}
	if (point != 12 || hash != 4 || str[len] != '\0')
		return (-1);
	return (0);
}

int		touch(char *str)
{
	int i;
	int tetris;

	tetris = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (((i + 1) < 21) && str[i + 1] == '#')
				tetris++;
			if (((i - 1) > -1) && str[i - 1] == '#')
				tetris++;
			if (((i + 5) < 21) && str[i + 5] == '#')
				tetris++;
			if (((i - 5) > -1) && str[i - 5] == '#')
				tetris++;
		}
		i++;
	}
	if (tetris != 6 && tetris != 8)
		return (-1);
	return (0);
}

int		isvalid(char *str, int len)
{
	if (goodchar(str, len) != 0)
		return (-1);
	if (touch(str) != 0)
		return (-1);
	return (0);
}
