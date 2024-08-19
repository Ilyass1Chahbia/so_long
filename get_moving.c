/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:43:53 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/21 19:18:41 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_it_lastdance(t_coord coor, t_infos *pic, char **rows, int btn)
{
	ft_printf("%d\n", pic->movez);
	pic->movez++;
	if (rows[(coor.row) - 1][coor.column] == 'X' && btn == 13)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[(coor.row) + 1][coor.column] == 'X' && btn == 1)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[coor.row][(coor.column) + 1] == 'X' && btn == 2)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[coor.row][(coor.column) - 1] == 'X' && btn == 0)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
}

void	up(t_infos *pic)
{
	t_coord	coor;
	char	**rows;

	rows = pic->rows;
	coor = position(rows, 0);
	if (rows[(coor.row) - 1][coor.column] != '1')
	{
		is_it_lastdance(coor, pic, rows, 13);
		if (!exit_door(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[(coor.row) - 1][coor.column] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_zhero, coor.column * 75, (coor.row - 1) * 75);
	}
}

void	down(t_infos *pic)
{
	t_coord	coor;
	char	**rows;

	rows = pic->rows;
	coor = position(rows, 0);
	if (rows[(coor.row) + 1][coor.column] != '1')
	{
		is_it_lastdance(coor, pic, rows, 1);
		if (!exit_door(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[(coor.row) + 1][coor.column] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_zhero, coor.column * 75, (coor.row + 1) * 75);
	}
}

void	left(t_infos *pic)
{
	t_coord	coor;
	char	**rows;

	rows = pic->rows;
	coor = position(rows, 0);
	if (rows[coor.row][coor.column - 1] != '1')
	{
		is_it_lastdance(coor, pic, rows, 0);
		if (!exit_door(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[coor.row][(coor.column) - 1] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_zhero, (coor.column - 1) * 75, coor.row * 75);
	}
}

void	right(t_infos *pic)
{
	t_coord	coor;
	char	**rows;

	rows = pic->rows;
	coor = position(rows, 0);
	if (rows[coor.row][coor.column + 1] != '1')
	{
		is_it_lastdance(coor, pic, rows, 2);
		if (!exit_door(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[coor.row][(coor.column) + 1] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_zhero, (coor.column + 1) * 75, coor.row * 75);
	}
}
