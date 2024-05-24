/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:32 by loic              #+#    #+#             */
/*   Updated: 2024/05/24 14:48:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_handler(char** user_input, char **envp)
{
	char **argument;
	argument = ft_split(user_input, ' ');
	//exec_command(char *command, char** argument, char **envp);
}

int		exec_command(char *command, char** argument, char **envp)
{
	char *command_path;

	command_path = "/bin/";
	// Maybe use strncat
	command_path = ft_strjoin(command_path, command);
	debug_display_array(argument);
	if (execve(command_path, argument, envp) == -1)
	{
		perror("execve_utils.c @ line 25 ");
		exit(EXIT_FAILURE);
	}
	return 0;
}