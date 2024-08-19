/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:28:40 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/22 14:23:33 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**filling(char **rows, int x, int y)
{
	if (!rows[y] || rows[y][x] == 'D' || rows[y][x] == '1')
		return (rows);
	rows[y][x] = 'D';
	rows = filling(rows, x + 1, y);
	rows = filling(rows, x - 1, y);
	rows = filling(rows, x, y + 1);
	rows = filling(rows, x, y - 1);
	return (rows);
}

void	map_len(char **rows)
{
	if (len_rowsofmap(rows) > 17)
	{
		write(1, "Error\n", 6);
		return (write(1, "Too Many Lines!", 16), free_func(rows), exit(1));
	}
	if (col_len(*rows) > 34)
	{
		write(1, "Error\n", 6);
		return (write(1, "Too Many Columns!", 18), free_func(rows), exit(1));
	}
}

void	map_check(char **rows)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	map_len(rows);
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E' || rows[m][n] == 'C')
			{
				write(2, "Error\ncan't reach a door or a brain", 35);
				free_func(rows);
				exit(1);
			}
			n++;
		}
		m++;
	}
}
