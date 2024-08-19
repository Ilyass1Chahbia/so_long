/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:30:07 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/21 19:25:18 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *row)
{
	int		x_axis;
	char	*maps;
	char	*tmp;

	tmp = NULL;
	x_axis = open(row, O_RDWR, 0777);
	if (x_axis < 0)
		return (write(1, "Error", 5), exit(1), NULL);
	maps = NULL;
	row = get_next_line(x_axis);
	while ((row))
	{
		maps = ft_strjoin(maps, row);
		free(row);
		row = NULL;
		row = get_next_line(x_axis);
	}
	return (close(x_axis), maps);
}
