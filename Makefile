NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = -Llibft


INC = minishell.h libft/libft.h


SRCS = main.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INC)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile libft $(INC)
		$(CC) -g $(CFLAGS) $(OBJS) $(LIB) -o $@

all: $(NAME)


FORCE:

libft: FORCE
		$(MAKE) -C libft

clean:
		$(MAKE) clean -C libft
		rm -rf $(OBJS)

fclean:
		$(MAKE) fclean -C libft
		rm -rf $(OBJS)
		rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) main.c minishell.h

.PHONY: all clean fclean re