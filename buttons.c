/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:44:41 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/08 12:53:18 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_exit_open(t_infos *pic)
{
	char	**rows;
	int		b;

	rows = pic->rows;
	b = coins_coll(rows);
	if (b == 0)
		gate_unl(rows, pic);
}

int	buttons(int button, void *p)
{
	t_infos	*pic;

	pic = p;
	if (button == 13)
		up(p);
	else if (button == 0)
		left(p);
	else if (button == 1)
		down(p);
	else if (button == 2)
		right(p);
	else if (button == 53)
		exit(0);
	is_exit_open(pic);
	return (0);
}

void	ren_again(t_infos *pic, t_coord coor, char **rows)
{
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_zfloor, coor.column * 75, coor.row * 75);
	if (rows[(coor.row)][coor.column] == 'E')
		mlx_put_image_to_window(pic->mlx_ptr,
			pic->mlx_window, pic->pic_zdoor, coor.column * 75, coor.row * 75);
}
