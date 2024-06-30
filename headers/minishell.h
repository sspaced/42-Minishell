/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:53 by loic              #+#    #+#             */
/*   Updated: 2024/06/30 22:38:57 by root             ###   ########.fr       */
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
#include <errno.h>

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
void			launch_pipe(char ***commands, t_envp_list **envp_list);
char			***create_command(char **argv);
void			close_fd(int **pipe_fd_tab);
int				**create_pipe_tab(int pipe_nb);
void free_int_array(int **array, int len);
void pipe_await(int pipe_fd_tab_len, int *fork_id_tab, int **pipe_fd_tab);
/*#########################################################################*/
///////wip
//[FILE] execve_utils.c
int				exec_command(char *command, char** argv, char **envp);
int				exec_command_v2(char *command, char** argument, t_envp_list **envp_list);
char			*check_path(char *command, char **splitted_path);

//[FILE] debug_utils.c
void			debug_display_array(char **array);
/*#########################################################################*/
#endif