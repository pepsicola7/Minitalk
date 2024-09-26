CC = cc
CFLAGS = -Wall -Werror -Werror
NAME = libftprintf.a
SRCS =	ft_printf.c\
		ft_fonction.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 
	
re: fclean all

.PHONY: clean fclean re all 