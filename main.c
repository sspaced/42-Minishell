/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/05/15 21:21:17 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		perror("main.c @ line 19 ");
// 		exit(EXIT_FAILURE);
// 	}
// 	int fork_id;

// 	fork_id = fork();
// 	if (fork_id == 0)
// 	{
// 		//printf("Main process, %s\n", argv[0]);
// 	}
// 	else 
// 	{
// 		exec_command(argv[1], argv + 1);
// 	}
// 	return (0);
// }

int	main(void)
{
	int fork_id;
	char **argument;
	while (1) 
	{
		char *user_input;
		user_input = readline("minishell$ ");
		if (!ft_strncmp("exit", user_input, 4) && ft_strlen(user_input) == 4)
		{
			printf("Goodbye !\n");
			free(user_input);
			break;
		}
		else 
		{
			fork_id = fork();
			if (fork_id == -1)
				return(perror("main.c @ line 44 "), EXIT_FAILURE);
			if (fork_id == 0)
			{
				argument = ft_split(user_input, ' ');
				exec_command(argument[0], argument + 1);
			}
			else
			{
				int status;
                waitpid(fork_id, &status, 0);
			}
			free(user_input);
		}
	}
	return (0);
}