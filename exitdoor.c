/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitdoor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:28:18 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/08 12:53:58 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_door(char **rows)
{
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E' || rows[m][n] == 'X')
				return (1);
			n++;
		}
		m++;
	}
	return (0);
}

int	coins_coll(char **rows)
{
	size_t	m;
	size_t	n;
	int		brainz;

	m = 0;
	n = 0;
	brainz = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'C')
				brainz++;
			n++;
		}
		m++;
	}
	return (brainz);
}

void	handle_door(t_infos *pic, char **rows, size_t m, size_t n)
{
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_zfloor, n * 75, m * 75);
	if (rows[m][n + 1] == '0')
		mlx_put_image_to_window(pic->mlx_ptr,
			pic->mlx_window, pic->pic_zfloor, (n + 1) * 75, m * 75);
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_zexit, n * 75, m * 75);
}

void	gate_unl(char **rows, t_infos *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E')
			{
				rows[m][n] = 'X';
				handle_door(pic, rows, m, n);
				break ;
			}
			n++;
		}
		m++;
	}
}
