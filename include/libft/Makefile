NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -crs
RM = rm -f
SRC = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c \
		ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c\
		 ft_calloc.c ft_isdigit.c ft_memcmp.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_isalnum.c\
		  ft_isprint.c ft_memcpy.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c\
		  ft_putendl_fd.c ft_putnbr_fd.c ft_freedom.c ft_atol.c ft_atoibutbetter.c ft_atodbl.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
