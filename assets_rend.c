/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_rend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:28:03 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/04/25 18:28:03 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(char **rows, t_infos *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == '1')
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_zwall, n * 75, m * 75);
			n++;
		}
		m++;
	}
}

void	render_hero(char **rows, t_infos *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'P')
			{
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_zhero, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	render_brainz(char **rows, t_infos *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'C')
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_brainz, n * 75, m * 75);
			n++;
		}
		m++;
	}
}

void	render_door(char **rows, t_infos *pic)
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
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, pic->pic_zdoor, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	render_floor(char **rows, t_infos *pic)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			mlx_put_image_to_window((pic)->mlx_ptr,
				(pic)->mlx_window, (pic)->pic_zfloor, j * 75, i * 75);
			j++;
		}
		i++;
	}
}
