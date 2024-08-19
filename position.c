/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:44:15 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/04/28 12:54:32 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	position(char **rows, int k)
{
	t_coord	pos;
	size_t	m;
	size_t	n;

	m = 0;
	n = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'P')
			{
				k = 1;
				break ;
			}
			n++;
		}
		if (k == 1)
			break ;
		m++;
	}
	return (pos.row = m, pos.column = n, pos);
}
