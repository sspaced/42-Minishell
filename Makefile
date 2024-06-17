NAME = minishell

CC = cc

CFLAGS = # -Wall -Wextra -Werror

LIB = -Llibft -lft -lreadline


INC = headers/minishell.h libft/libft.h


SRCS = 	main.c\
		utils/execve_utils.c\
		utils/debug_utils.c\
		utils/general_utils/general_utils.c\
		utils/envp_utils/envp_list_utils.c\
		utils/envp_utils/envp_list_init.c\
		utils/envp_utils/envp_list_tools.c\
		builtins/env.c\
		builtins/export.c\
		builtins/unset.c\


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