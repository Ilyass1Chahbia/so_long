/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:32:16 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/21 19:25:34 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_zdoor(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_zdoor = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/zdoor.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_zdoor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the door's image!", 27);
		free(pic);
		exit (1);
	}
}

void	get_zexit(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_zexit = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/exit.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_zexit))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the exit image!", 25);
		free(pic);
		exit (1);
	}
}

void	get_zwall(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_zwall = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/z_wall.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_zwall))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the wall's image!", 27);
		free(pic);
		exit (1);
	}
}

void	get_floor(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_zfloor = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/background.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_zfloor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the floor's image!", 28);
		free(pic);
		exit (1);
	}
}

void	get_brainz(t_infos *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_brainz = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/brainz.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_brainz))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the brainz's image!", 29);
		free(pic);
		exit (1);
	}
}
