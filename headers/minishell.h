/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:53 by loic              #+#    #+#             */
/*   Updated: 2024/08/07 19:22:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40684
# endif

// struct
typedef struct s_envp_list
{
	char			*key;
	char			*value;
	struct s_envp_list	*next;
}					t_envp_list;

//[FOLDER] builtins
//[FILE] env.c
void			display_envp(t_envp_list **envp_list);
//[FILE] export.c
int				export_envp(t_envp_list **envp_list, char *user_input);
//[FILE] unset.c
void			unset_envp(t_envp_list **envp_list, char *user_input);
//[FILE] cd.c
void			change_directory(char *user_input);
/*#########################################################################*/
//[FOLDER] utils

//[FOLDER] general_utils
//[FILE] general_utils.c
size_t			str_len_until(char	*str, char	until_char);
size_t			array_len(char **array);
size_t			array_array_len(char ***array);
size_t			array_len_gen(int **array);
void			clear_array(char **array);
void			clear_int_array(int **array, int len);
//[FOLDER] envp_utils
//[FILE] envp_list_utils.c
void			list_add_back(t_envp_list **lst, t_envp_list *new);
t_envp_list		*list_last(t_envp_list *lst);
t_envp_list		*envp_list_create_node(char	*key, char	*value);
void			envp_list_clear(t_envp_list	**envp_list);
void			del_one(t_envp_list *envp_to_del);
void			re_link_node(t_envp_list **envp_previous, t_envp_list **envp_head, t_envp_list **envp_next);
//[FILE] envp_list_init.c
int				fill_envp_list(t_envp_list **envp_list, char **envp);
char			**extract_key_value(char *envp_line);
//[FILE] envp_list_tools.c
char			*envp_list_get(t_envp_list **envp_list, char *key);
int				envp_list_add(t_envp_list **envp_list, char *key, char *value);
int				envp_list_del(t_envp_list **envp_list, char *key);
char			**envp_linked_to_list(t_envp_list **envp_list);
size_t			envp_len(t_envp_list **envp_list);
//[FOLDER] pipe_utils
//[FILE] pipe_utils.c
void			launch_pipe(char ***commands, t_envp_list **envp_list);
char			***create_command(char **argv);
void			close_fd(int **pipe_fd_tab);
int				**create_pipe_tab(int pipe_nb);
void			pipe_await(int pipe_fd_tab_len, int *fork_id_tab, int **pipe_fd_tab);
//[FOLDER] history_utils
//[FILE] history_utils.c
char			*strdup_until(const char *str, char until_char);
int				load_history(int history_file);
int				add_history_custom(char *user_input, int history_file);
/*#########################################################################*/
//[FOLDER] get_next_line
//[FILE] get_next_line_utils.c
size_t			ft_strlen_gnl(char const *str, int mode);
char			*ft_strjoin_gnl(char const *s1, char const *s2, char *temp_line);
//[FILE] get_next_line.c
void			make_stash(char *line, char *buff);
char			*make_line(char *line, char *buff);
char			*stock_line(char *line, char *buff, ssize_t *byte_len, int fd);
char			*get_next_line(int fd);
/*#########################################################################*/
//[FOLDER] redirection
//[FILE] redirection.c
int				open_or_check_fd(char *target, int mode);
int				redirect_input(char *target, int source);
int				redirect_output(char *target, int source, int mode);
/*#########################################################################*/
///////wip
//[FILE] execve_utils.c
int				exec_command(char *command, char** argv, char **envp);
int				exec_command_v2(char *command, char** argument, t_envp_list **envp_list);
char			*check_path(char *command, char **splitted_path);

//[FILE] debug_utils.c
void			debug_display_array(char **array);
/*#########################################################################*/

// Tomux
typedef enum e_lexer
{
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    DOLLAR,
    GREATER,
    GREATER2,
    SMALLER,
    SMALLER2,
    PIPE,
    WORD,
}t_lexer;

typedef struct s_input
{
    t_lexer type;
    char *value;
    struct s_input *next;
} t_input;

void handle_greater(char *input, int *i, t_input **tokens);
void handle_smaller(char *input, int *i, t_input **tokens);
void handle_special_chars(char *input, int *i, t_input **tokens);
void handle_quotes(char *input, int *i, t_input **tokens, char quote_type);
void handle_word(char *input, int *i, t_input **tokens);
void tokenize_input(char *input, t_input **tokens);
t_input *create_token(t_lexer type, char *value);
void add_token(t_input **tokens, t_input *new_token);
void free_tokens(t_input *tokens);
char *expand_variable(const char *var);
char *extract_env_name(const char *str);
int is_env_variable(const char *str);
void expand_variables_in_tokens(t_input *tokens);
char *concatenate_values(char *value1, char *value2);
char *extract_double_quoted_value(char *input, int *i);
char *extract_single_quoted_value(char *input, int *i);
char ***tokens_to_array(t_input *tokens);
int count_tokens(t_input *tokens);

#endif