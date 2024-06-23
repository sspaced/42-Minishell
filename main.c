/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/06/24 00:00:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

//[BUG] With "exit" need to type 2 time to work.
int	main(int argc, char **argv, char *envp[])
{
	int fork_id;
	char *user_input;
	char **argument;
	int status;
	t_envp_list	*envp_list;
	
	envp_list = NULL;
	
	if (argc != 1 || !argv[0])
		return(perror("main.c @ line 26 "), EXIT_FAILURE);
	if (!fill_envp_list(&envp_list, envp))
		return(perror("main.c @ line 28 "), envp_list_clear(&envp_list), EXIT_FAILURE);
	while (1)
	{
		user_input = readline("minishell$ ");
		if (user_input != NULL)
			add_history(user_input);
		if (ft_strlen(user_input) == 4 && !ft_strncmp("exit", user_input, 4))
		{
			printf("exit\n");
			free(user_input);
			exit(errno);
		}
		else if (ft_strlen(user_input) == 3 && !ft_strncmp("env", user_input, 3))
		{
			display_envp(&envp_list);
			free(user_input);
		}
		else if (ft_strlen(user_input) >= 6 && !ft_strncmp("export", user_input, 6))
		{
			export_envp(&envp_list, user_input);
			free(user_input);
		}
		else if (ft_strlen(user_input) >= 5 && !ft_strncmp("unset", user_input, 5))
		{
			unset_envp(&envp_list, user_input);
			free(user_input);
		}
		else if (ft_strlen(user_input) >= 2 && !ft_strncmp("cd", user_input, 2))
		{
			change_directory(user_input);
			free(user_input);
		}
		else
		{
			fork_id = fork();
			if (fork_id == -1)
				return(perror("main.c @ line 37 "), EXIT_FAILURE);
			if (fork_id == 0)
			{
				argument = ft_split(user_input, ' ');
				exec_command_v2(argument[0], argument, &envp_list, envp);
			}
			else
                waitpid(fork_id, &status, 0);
			free(user_input);
		}
	}
	return (0);
}

//[Debug] test envp function
// int main(int argc, char **argv, char *envp[])
// {
// 	if (argc != 1 || !argv[0])
// 		return(perror("main.c @ line 19 "), EXIT_FAILURE);
// 	t_envp_list	*envp_list;

// 	envp_list = NULL;
	
// 	//[TODO] test error handling, malloc == null, valgring, fsanitize
// 	if (!fill_envp_list(&envp_list, envp))
// 		return(perror("main.c/debug @ line 63 "), envp_list_clear(&envp_list), EXIT_FAILURE);
	
// 	char *arg = "ls";
// 	char **option = ft_split(arg, ' ');
// 	exec_command_v2("ls", option, &envp_list, envp);
// 	clear_array(option);
	
// 	// export_envp(&envp_list, "export ke=value");
// 	// display_envp(&envp_list);
// 	// export_envp(&envp_list, "export key=value");c
// 	// unset_envp(&envp_list, "unset ke");
// 	// display_envp(&envp_list);
// 	envp_list_clear(&envp_list);
// }