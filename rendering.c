/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:30:12 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/22 17:12:29 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_function(t_infos *pic)
{
	free(pic);
	exit(0);
}

void	render(char *map)
{
	t_infos	*pic;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (write(1, "Error!", 1), free(map), exit(1));
	pic = malloc(sizeof(t_infos));
	if (!pic)
		return (free(map), exit (1));
	pic->rows = ft_split(map, '\n');
	pic->movez = 1;
	free(map);
	fetch_pic(pic, mlx_ptr);
	render_floor(pic->rows, pic);
	render_wall(pic->rows, pic);
	render_door(pic->rows, pic);
	render_hero(pic->rows, pic);
	render_brainz(pic->rows, pic);
	mlx_hook(pic->mlx_window, 2, 0, buttons, pic);
	mlx_hook(pic->mlx_window, 17, 0, x_function, pic);
	mlx_loop(pic->mlx_ptr);
}
