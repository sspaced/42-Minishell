/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:32 by loic              #+#    #+#             */
/*   Updated: 2024/05/15 20:57:59 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_command(char *command, char** argument)
{
	char *command_path;

	command_path = "/bin/";
	// Maybe use strncat
	command_path = ft_strjoin(command_path, command);
	if (execve(command_path, argument, NULL) == -1)
	{
		perror("main.c @ line 23 ");
		exit(EXIT_FAILURE);
	}
	return 0;
}