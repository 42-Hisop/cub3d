CC= gcc
CFLAGS= -L . -lmlx -framework OpenGL -framework Appkit 
SRCS= main.c /
	fnc.c /
	map_cut.c /
	map_valid.c /
	player_init.c /
	raycast.c /
	raycast2.c /
	check_map.c /
	init_texture.c /
	draw_screen.c /
	utils/utils.c /
	utils/split_line.c /
	utils/split_utils.c 

OBJS= $(SRCS:.c=.o)
NAME= cub3D

$(NAME): $(OBJS)
	-o $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
