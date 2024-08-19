/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:29:20 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/04/25 18:29:23 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*rest_of_fd(char *str)
{
	char	*remain;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	remain = malloc(ft_strlen(str) - i + 1);
	if (!remain)
		return (0);
	while (str[i])
		remain[n++] = str[i++];
	remain[n] = '\0';
	return (free(str), remain);
}

static char	*line_return(char *str)
{
	int		i;
	int		n;
	char	*res;

	i = 0;
	n = 0;
	if (!(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (0);
	while (n < i)
	{
		res[n] = str[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}

static char	*reading(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (bytes > 0 && ft_strchr(str, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = reading(str, fd);
	if (!str)
		return (0);
	result = line_return(str);
	str = rest_of_fd(str);
	return (result);
}
