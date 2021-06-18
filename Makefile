CC= gcc
CFLAGS= -L ./mlx -lmlx -framework OpenGL -framework Appkit
SRCS= main.c \
	  fnc.c \
	  map_cut.c \
	  map_valid.c \
	  player_init.c \
	  split_line.c \
	  split_utils.c \
	  check_map.c \
	  init_texture.c \
	  raycast.c \
	  raycast2.c \
	  utils.c \
	  draw_screen.c \

OBJS= $(SRCS:.c=.o)
NAME= cub3D

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJS):
	$(CC) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
