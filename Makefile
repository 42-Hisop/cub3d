# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 20:32:45 by khee-seo          #+#    #+#              #
#    Updated: 2021/07/01 20:33:24 by khee-seo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
MLX= -L ./mlx -lmlx -framework OpenGL -framework Appkit
SRCS= main.c \
	  fnc.c \
	  map_cut.c \
	  map_valid.c \
	  player_init.c \
	  split_line.c \
	  split_utils.c \
	  check_map.c \
	  texture_init.c \
	  raycast.c \
	  raycast2.c \
	  utils.c \
	  draw_screen.c \
	  key_press.c \
	  turn_player.c \


OBJS= $(SRCS:.c=.o)
NAME= cub3D

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(MLX) -o $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
