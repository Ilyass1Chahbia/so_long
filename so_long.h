/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:30:21 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/13 15:49:02 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct p_coord
{
	int	row;
	int	column;
}		t_coord;

typedef struct infos_struct
{
	char	**rows;
	int		pic_width;
	int		pic_height;
	int		movez;
	void	*pic_zdoor;
	void	*pic_zexit;
	void	*pic_zwall;
	void	*pic_zfloor;
	void	*pic_brainz;
	void	*pic_zhero;
	void	*mlx_ptr;
	void	*mlx_window;
}		t_infos;

char	*get_next_line(int fd);
int		ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	first_row(char **rows);
void	sidez(char **rows);
void	last_row(char **rows);
void	map_parsing(char **lines, char *maps);
char	**filling(char **lines, int x, int y);
char	*read_map(char *line);
void	map_check(char **lines);
void	name_error(char *name);
void	render(char *maps);
void	get_zdoor(t_infos *pic, void *mlx_ptr);
void	get_zexit(t_infos *pic, void *mlx_ptr);
void	get_zwall(t_infos *pic, void *mlx_ptr);
void	get_floor(t_infos *pic, void *mlx_ptr);
void	get_brainz(t_infos *pic, void *mlx_ptr);
t_infos	fetch_pic(t_infos *img, void *mlx_ptr);
int		buttons(int button, void *p);
void	up(t_infos *pic);
void	left(t_infos *pic);
void	down(t_infos *pic);
void	right(t_infos *pic);
t_coord	position(char **lines, int k);
size_t	len_rowsofmap(char **lines);
size_t	col_len(char *lines);
void	render_floor(char **rows, t_infos *pic);
void	render_wall(char **rows, t_infos *pic);
void	render_hero(char **rows, t_infos *pic);
void	render_brainz(char **rows, t_infos *pic);
void	render_door(char **rows, t_infos *pic);
int		coins_coll(char **lines);
void	gate_unl(char **lines, t_infos *map);
int		exit_door(char **lines);
void	checking_the_line(char **lines);
int		ft_putnbr(int n);
int		ft_printf(const char *f, ...);
int		ft_putchar(char c);
void	ren_again(t_infos *pic, t_coord coor, char **rows);
void	free_func(char **rows);

#endif
