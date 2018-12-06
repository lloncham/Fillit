/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:32:21 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/06 15:12:38 by fcazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		goodchar(char *str)
{
	int i;
	int point;
	int hash;
	
	i = 0;
	point = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '.')
				point++;
			if (str[i] == '#')
				hash++;
		}
		else
		{
			if (str[i] != '\n')
				return (-1);
		}
		i++;
	}
	if (str[20] != '\n' && str[20] != '\0')
		return (-2);
	if (point != 12 || hash != 4)
		return (-3);
	return (0);
}

int		touch(char *str)
{
	int i;
	int tetri;

	tetri = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				tetri++;
			if (str[i - 1] == '#')
				tetri++;
			if (str[i + 5] == '#')
				tetri++;
			if (str[i - 5] == '#')
				tetri++;
		}
		i++;
	}
	if (tetri != 6 && tetri != 8)
		return (-4);
	return (0);
}

int		isvalid(char *str)
{
	if (goodchar(str) != 0)
		return (-1);
	if (touch(str) != 0)
		return (-1);
	return (0);
}
