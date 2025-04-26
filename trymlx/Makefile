NAME = tryme

CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRC = \
		try1.c\


OBJS = $(SRC:.c=.o)

RM = rm -f

VPATH = source
#Libs
MLX_PATH = ./include/mlx-linux
MLX = $(MLX_PATH)/libmlx.a

%.o: %.c
		$(CC) $(CFLAGS) -c $< -I$(MLX_PATH) -I include -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx -lX11 -lXext -o $(NAME)
$(MLX): 
		make -s -C $(MLX_PATH)

clean:
		$(RM) $(OBJS)
fclean:
		$(RM) $(NAME)
		make clean -C $(MLX_PATH)

re:  fclean all

.PHONY: all clean fclean re
