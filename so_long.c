/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:30:17 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/23 12:11:38 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_error(char *name)
{
	int	ls;

	ls = col_len(name) - 1;
	if (name[ls - 3] != '.' || name[ls - 2] != 'b'
		|| name[ls - 1] != 'e' || name[ls] != 'r')
	{
		write(1, "Error!\n", 8);
		return (write(1, "map file extention not valid\n", 29), exit (1));
	}
}

void	nv_map(char *map)
{
	if (!map)
	{
		write(1, "Error\n", 8);
		return (write(1, "map denied", 11), exit (1));
	}
}

void	check_and_rend(char **rows, char *map)
{
	map_check(rows);
	render(map);
}

int	main(int argc, char **argv)
{
	char	*x_axis;
	char	*map;
	char	**rows;
	t_coord	player;

	if (argc != 2)
		return (write(1, "Error\nWrong number of arguments!", 32), exit (1), 0);
	else if (argc == 2)
	{
		x_axis = argv[1];
		name_error(x_axis);
		map = read_map(x_axis);
		nv_map(map);
		rows = ft_split(map, '\n');
		if (!rows)
			return (free(map), 0);
		map_parsing(rows, map);
		player = position(rows, 0);
		rows = filling(rows, player.column, player.row);
		check_and_rend(rows, map);
	}
}
