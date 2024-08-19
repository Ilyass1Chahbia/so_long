/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:28:27 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/21 17:40:23 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_zhero(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_zhero = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/zhero.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_zhero))
	{
		write(1, "Error!\n", 8);
		write(1, "can't get the zhero's image!", 29);
		free(pic);
		exit (1);
	}
}

void	open_window(t_infos *pic, void *mlx_ptr, char **rows)
{
	pic->mlx_ptr = mlx_ptr;
	pic->mlx_window = mlx_new_window(pic->mlx_ptr,
			pic->pic_width * col_len(*rows),
			pic->pic_height * len_rowsofmap(rows), "so long");
	if (!(pic->mlx_window))
	{
		write(1, "Error!\n", 8);
		write(1, "can't open the window!", 23);
		free(pic);
		exit (1);
	}
}

t_infos	fetch_pic(t_infos *pic, void *mlx_ptr)
{
	char	**rows;

	rows = pic->rows;
	pic->mlx_ptr = mlx_ptr;
	get_floor(pic, mlx_ptr);
	get_zwall(pic, mlx_ptr);
	get_zdoor(pic, mlx_ptr);
	get_zexit(pic, mlx_ptr);
	get_brainz(pic, mlx_ptr);
	get_zhero(pic, mlx_ptr);
	open_window(pic, mlx_ptr, rows);
	return (*pic);
}
