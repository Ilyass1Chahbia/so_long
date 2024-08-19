/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:08:29 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/22 14:21:11 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_row(char **rows)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (rows[m][n])
	{
		if (rows[0][n] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surronded with walls", 35);
			free_func(rows);
			exit (1);
		}
		n++;
	}
}

void	sidez(char **rows)
{
	size_t	m;
	size_t	n;
	size_t	r;

	m = 0;
	r = col_len(*rows);
	n = 0;
	while (rows[m])
	{
		if (rows[m][n] != '1' || rows[m][r - 1] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surronded with walls", 35);
			free_func(rows);
			exit (1);
		}
		m++;
	}
}

void	last_row(char **rows)
{
	size_t	m;
	size_t	n;
	size_t	r;

	m = 0;
	r = len_rowsofmap(rows);
	n = 0;
	while (rows[r - 1][n])
	{
		if (rows[r - 1][n] != '1')
		{
			write(1, "Error!\n", 7);
			write(1, "Map not fully surronded with walls", 35);
			free_func(rows);
			exit (1);
		}
		n++;
	}
}
