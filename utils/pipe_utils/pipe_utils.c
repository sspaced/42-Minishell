/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:50:54 by root              #+#    #+#             */
/*   Updated: 2024/06/27 17:48:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int		**create_pipe(int nb_pipe)
// {
// 	int	**pipe_fd_tab;
// 	int counter;

// 	counter = 0;
// 	pipe_fd_tab = malloc(sizeof(int *) * nb_pipe);
	
// 	while(nb_pipe)
// 	{
// 		pipe_fd_tab[counter] = malloc(sizeof(int *) * 2);
// 		if (pipe(pipe_fd_tab[counter]) == -1)
// 			return (NULL);
// 		nb_pipe--;
// 		counter++;
// 	}
// 	return (pipe_fd_tab);
// }

//[TODO] Need to secure everything
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
			return (NULL);
		if (pipe(pipe_fd) == -1)
			return (NULL);
		pipe_fd_tab[index] = pipe_fd;
		index++;
		pipe_nb--;
	}
	return (pipe_fd_tab);
}

void	close_specific_fd(int **pipe_fd_tab, int exclude, int exclude_2)
{
	int tab_len;
	int index;
	int index_2;

	index = 0;
	index_2 = 0;
	tab_len = array_len_gen(pipe_fd_tab);
	while(index < tab_len)
	{
		while (index_2 < 2)
		{
			if (pipe_fd_tab[index][index_2] != exclude && pipe_fd_tab[index][index_2] != exclude_2)
				close(pipe_fd_tab[index][index_2]);
			index_2++;
		}
		index_2 = 0;
		index++;
	}
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

void	handle_child(char **command, int **pipe_fd_tab, int pipe_fd_tab_len, int index, t_envp_list **envp_list, char **envp)
{	
	if (index < pipe_fd_tab_len)
		dup2(pipe_fd_tab[index][1], STDOUT_FILENO);
	if (index > 0)
		dup2(pipe_fd_tab[index - 1][0], STDIN_FILENO);
	close_all_fd(pipe_fd_tab, pipe_fd_tab_len);
	if (!exec_command_v2(command[0], command, envp_list, envp))
		printf("failed\n");
}

void	launch_pipe(char ***commands, t_envp_list **envp_list, char **envp)
{
	int **pipe_fd_tab;
	int pipe_fd_tab_len;
	int fork_id;
	int nb_command;
	int index;
	int *fork_id_tab;
	int status;

	pipe_fd_tab_len = array_array_len(commands) - 1;
	pipe_fd_tab = create_pipe_tab(pipe_fd_tab_len);
	nb_command = array_array_len(commands);
	fork_id_tab = malloc(sizeof(int) * nb_command);
	index = 0;
	fork_id = 0;

	while (index < nb_command)
	{
		if (index == 0 || fork_id != 0)
			fork_id = fork();
		fork_id_tab[index] = fork_id;
		if (fork_id == 0)
		{
			handle_child(commands[index], pipe_fd_tab, pipe_fd_tab_len, index,envp_list, envp);
			break;
		}
		index++;
	}
	close_all_fd(pipe_fd_tab, pipe_fd_tab_len);
	index = 0;
	while (index < nb_command)
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
