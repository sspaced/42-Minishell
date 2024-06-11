/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/06/12 00:10:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

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
		if (ft_strlen(user_input) == 4 && !ft_strncmp("exit", user_input, 4))
		{
			printf("Goodbye !\n");
			free(user_input);
			break;
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
		else
		{
			fork_id = fork();
			if (fork_id == -1)
				return(perror("main.c @ line 37 "), EXIT_FAILURE);
			if (fork_id == 0)
			{
				argument = ft_split(user_input, ' ');
				exec_command(argument[0], argument, envp);
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
// 	//display_envp(&envp_list);
// 	//printf("value %s\n", envp_list_get(&envp_list, "SSPACE"));
// 	// if (!envp_list_add(&envp_list, "SSPACE", "test"))
// 	// 	return(perror("main.c/debug @ line 68 "), envp_list_clear(&envp_list), EXIT_FAILURE);
// 	// if (!envp_list_add(&envp_list, "HELLO", "hi !"))
// 	// 	return(perror("main.c/debug @ line 68 "), envp_list_clear(&envp_list), EXIT_FAILURE);
// 	//envp_list_del(&envp_list, "SSPACEE");
// 	export_envp(&envp_list, "");
// 	display_envp(&envp_list);
// 	envp_list_clear(&envp_list);
// }
