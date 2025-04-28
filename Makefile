NAME = fractol

OS = $(shell uname)

CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRC = \
		fractol.c\



OBJS = $(SRC:.c=.o)

RM = rm -f

#Libs
LIBFT_PATH = ./include/libft
LIBFT = $(LIBFT_PATH)/libft.a
VPATH = source

MLX_PATH = ./mlx-linux
MLX = $(MLX_PATH)/libmlx.a

%.o: %.c
		$(CC) $(CFLAGS) -c $< -I$(LIBFT_PATH) -I$(MLX_PATH) -I include -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lX11 -lXext -o $(NAME)

$(LIBFT): 
		make -s -C $(LIBFT_PATH)
$(MLX): 
		make -s -C $(MLX_PATH)

clean:
		$(RM) $(OBJS)
fclean:
		$(RM) $(NAME)
		make fclean -C $(LIBFT_PATH)
		make clean -C $(MLX_PATH)

re:  fclean all

.PHONY: all clean fclean re
