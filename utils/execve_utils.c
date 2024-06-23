/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:32 by loic              #+#    #+#             */
/*   Updated: 2024/06/23 23:54:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// int		exec_command(char *command, char** argument, char **envp)
// {
// 	char *command_path;
// 	command_path = "/bin/";
// 	// Maybe use strncat
// 	command_path = ft_strjoin(command_path, command);
// 	if (execve(command_path, argument, envp) == -1)
// 	{
// 		perror("execve_utils.c @ line 25 ");
// 		exit(EXIT_FAILURE);
// 	}
// 	return 0;
// }

//[TODO] Make a function that reverse the link list back into a char **envp to not use envp[] anymore.
int		exec_command_v2(char *command, char** argument, t_envp_list **envp_list, char **envp)
{
	char	*command_path;
	char	*path;
	char	**splitted_path;
	
	path = envp_list_get(envp_list, "PATH");
	if (!path)
		return(printf("No PATH set !\n"), 0);
	splitted_path = ft_split(path, ':');
	if (!splitted_path)
		return (0);
	command_path = check_path(command, splitted_path);
	clear_array(splitted_path);
	if (!command_path)
		return(0);
	if (execve(command_path, argument, envp) == -1)
		return (perror("execve_utils.c @ line 25 "), free(command_path), 0);
	return (free(command_path), 1);
}

//[Secured]
char	*check_path(char *command, char **splitted_path)
{
	char	*command_path;
	char	*command_path_buff;
	
	command = ft_strjoin("/", command);
	if (!command)
		return (NULL);
	while (*splitted_path)
	{
		command_path = ft_strjoin(*splitted_path, command);
		if (!command_path)
			return (free(command), NULL);
		if (access(command_path, X_OK) == 0)
			return (free(command), command_path);
		free(command_path);
		splitted_path++;
	}
	return (perror(command + 1), free(command), NULL);
}
