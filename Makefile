# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 18:29:47 by ilchahbi          #+#    #+#              #
#    Updated: 2024/06/22 14:24:58 by ilchahbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc 

FLAGS = -Wall -Wextra -Werror -Imlx

SRC = so_long.c assets_rend.c buttons.c exitdoor.c read_map.c fetch_pic.c ft_printf.c ft_putchar.c get_pic.c floodfill.c ft_putnbr.c ft_split.c get_next_line.c get_next_line_utils.c ft_length.c get_moving.c parsing.c position.c rendering.c wall_cases.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean