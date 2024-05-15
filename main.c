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
	while (1) 
	{
		char *user_input = readline("minishell$ ");
		if (!ft_strncmp("exit", user_input, 4))
		{
			printf("Goodbye !\n");
			free(user_input);
			break;
		}
		else 
		{
			printf("%s\n", user_input);
			free(user_input);
		}
	}
	return (0);
}
