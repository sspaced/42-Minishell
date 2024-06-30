/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:50:54 by root              #+#    #+#             */
/*   Updated: 2024/06/27 21:57:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void free_int_array(int **array, int len)
{
	int index;

	index = 0;
	while(index < len)
	{
		if (array[index] != NULL)
			free(array[index]);
		index++;
	}
	free(array);
}

//[SECURED]
int **create_pipe_tab(int pipe_nb)
{
	int *pipe_fd;
	int index;
	int **pipe_fd_tab;
	pipe_fd_tab = malloc(sizeof(int *) * pipe_nb);
	if (!pipe_fd_tab)
		return (NULL);
	index = 0;
	while (pipe_nb)
	{
		pipe_fd = malloc(sizeof(int) * 2);
		if (!pipe_fd)
			return (free_int_array(pipe_fd_tab, index), NULL);
		if (pipe(pipe_fd) == -1)
			return (free(pipe_fd), free_int_array(pipe_fd_tab, index), NULL);
		pipe_fd_tab[index] = pipe_fd;
		index++;
		pipe_nb--;
	}
	return (pipe_fd_tab);
}

void	close_all_fd(int **pipe_fd_tab, int pipe_fd_tab_len)
{
	int index;

	index = 0;
	while(index < pipe_fd_tab_len)
	{
		close(pipe_fd_tab[index][0]);
		close(pipe_fd_tab[index][1]);
		index++;
	}
}

void	handle_child(char **command, int **pipe_fd_tab, int pipe_fd_tab_len, int index, t_envp_list **envp_list)
{	
	if (index < pipe_fd_tab_len)
		dup2(pipe_fd_tab[index][1], STDOUT_FILENO);
	if (index > 0)
		dup2(pipe_fd_tab[index - 1][0], STDIN_FILENO);
	close_all_fd(pipe_fd_tab, pipe_fd_tab_len);
	if (!exec_command_v2(command[0], command, envp_list))
		printf("failed\n");
}

void	launch_pipe(char ***commands, t_envp_list **envp_list)
{
	int **pipe_fd_tab;
	int pipe_fd_tab_len;
	int fork_id;
	int index;
	int *fork_id_tab;
	int status;

	pipe_fd_tab_len = array_array_len(commands) - 1;
	pipe_fd_tab = create_pipe_tab(pipe_fd_tab_len);
	fork_id_tab = malloc(sizeof(int) * pipe_fd_tab_len + 1);
	index = 0;
	fork_id = 0;

	while (index < (pipe_fd_tab_len + 1))
	{
		if (index == 0 || fork_id != 0)
			fork_id = fork();
		fork_id_tab[index] = fork_id;
		if (fork_id == 0)
		{
			handle_child(commands[index], pipe_fd_tab, pipe_fd_tab_len, index,envp_list);
			break;
		}
		index++;
	}
	close_all_fd(pipe_fd_tab, pipe_fd_tab_len);
	index = 0;
	while (index < (pipe_fd_tab_len + 1))
	{
		waitpid(fork_id_tab[index], &status, 0);
		index++;
	}
}

//[TEMP]
char	***create_command(char **argv)
{
	int			pipe_nb;
	int			index;
	char		**splited_input;
	char		***commands;
	char		**command;
	
	splited_input = ft_split(argv[1], '|');
	pipe_nb = array_len(splited_input);
	commands = malloc((pipe_nb + 1) * sizeof(char**));
	index = 0;
	while (pipe_nb)
	{
		command = ft_split(splited_input[index], ' ');
		commands[index] = command;
		index++;
		pipe_nb--;
	}
	commands[index] = NULL;
	return (commands);
}
