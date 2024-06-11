/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:53 by loic              #+#    #+#             */
/*   Updated: 2024/06/12 00:11:18 by root             ###   ########.fr       */
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

// struct
typedef struct s_envp_list
{
	char			*key;
	char			*value;
	struct s_envp_list	*next;
}					t_envp_list;

//[FOLDER] builtins
//[FILE] env.c
void	display_envp(t_envp_list **envp_list);
//[FILE] export.c
int export_envp(t_envp_list **envp_list, char *user_input);
//[FILE] unset.c
/*#########################################################################*/
//[FOLDER] utils

//[FOLDER] general_utils
//[FILE] general_utils.c
size_t			str_len_until(char	*str, char	until_char);
size_t			array_len(char **array);
void			clear_array(char **array);
//[FOLDER] envp_utils
//[FILE] envp_list_utils.c
void			list_add_back(t_envp_list **lst, t_envp_list *new);
t_envp_list		*list_last(t_envp_list *lst);
t_envp_list		*envp_list_create_node(char	*key, char	*value);
void			envp_list_clear(t_envp_list	**envp_list);
//[FILE] envp_list_init.c
int				fill_envp_list(t_envp_list **envp_list, char **envp);
char			**extract_key_value(char *envp_line);
//[FILE] envp_list_tools.c
char	*envp_list_get(t_envp_list **envp_list, char *key);
int		envp_list_add(t_envp_list **envp_list, char *key, char *value);
int		envp_list_del(t_envp_list **envp_list, char *key);
void	del_one(t_envp_list *envp_to_del);
void	re_link_node(t_envp_list **envp_previous, t_envp_list **envp_head, t_envp_list **envp_next);
/*#########################################################################*/
///////wip
//[FILE] execve_utils.c
int				exec_command(char *command, char** argv, char **envp);
void			check_path(char *cmd);

//[FILE] debug_utils.c
void			debug_display_array(char **array);
/*#########################################################################*/
#endif