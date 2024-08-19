/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:55:31 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/21 19:15:21 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	len_rowsofmap(char **rows)
{
	size_t	l;

	l = 0;
	while (rows[l])
	{
		l++;
	}
	return (l);
}

size_t	col_len(char *rows)
{
	size_t	n;

	n = 0;
	while (rows[n])
		n++;
	return (n);
}

void	checking_the_line(char **rows)
{
	size_t	n;
	size_t	l;
	size_t	j;

	n = 0;
	l = col_len(rows[n]);
	while (rows[n])
	{
		j = col_len(rows[n]);
		if (j != l)
		{
			write(2, "Error\nmap isn't a full rectangle", 32);
			free_func(rows);
			exit(0);
		}
		n++;
	}
}

void	free_func(char **rows)
{
	int	f;

	f = 0;
	while (rows[f])
	{
		free(rows[f]);
		f++;
	}
	free(rows);
}
