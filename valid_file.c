/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_FILE.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:20 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/12 17:45:18 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		goodchar(char *str, int len)
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
			//bezarre
			if (str[i] != '\n')
				return (-1);
		}
		i++;
	}
	if (str[len] != '\0')
		return (-1); 
	//bezarre
	if (point != 12 || hash != 4)
		return (-1);
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
			if (((i + 1) < 21) && str[i + 1] == '#')
				tetri++;
			if (((i - 1) > -1) && str[i - 1] == '#')
				tetri++;
			if (((i + 5) < 21) && str[i + 5] == '#')
				tetri++;
			if (((i - 5) > -1) && str[i - 5] == '#')
				tetri++;
		}
		i++;
	}
	if (tetri != 6 && tetri != 8)
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
