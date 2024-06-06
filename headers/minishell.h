/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:53 by loic              #+#    #+#             */
/*   Updated: 2024/06/06 23:30:30 by root             ###   ########.fr       */
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

// envp_utils.c
typedef struct s_envp_list
{
	char			*key;
	char			*value;
	struct s_envp_list	*next;
}					t_envp_list;

size_t		strlen_until(char	*str, char	until_char);
char		**extract_key_value(char *envp_line);
t_envp_list	*lstlast(t_envp_list *lst);
void		lstadd_back(t_envp_list **lst, t_envp_list *new);
int			fill_envp_list(t_envp_list **envp_list, char **envp);
void		display_envp_list(t_envp_list **envp_list);


// execve_utils.c
int			exec_command(char *command, char** argv, char **envp);
void		check_path(char *cmd);

// debug_utils.c
void		debug_display_array(char **array);
#endif