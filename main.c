/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/06/06 23:36:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

// int	main(int argc, char **argv, char *envp[])
// {
// 	int fork_id;
// 	char *user_input;
// 	char **argument;
// 	int status;
	
	
// 	if (argc != 1 || !argv[0])
// 		return(perror("main.c @ line 19 "), EXIT_FAILURE);
// 	while (1)
// 	{
// 		user_input = readline("minishell$ ");
// 		if (ft_strlen(user_input) == 4 && !ft_strncmp("exit", user_input, 4))
// 		{
// 			printf("Goodbye !\n");
// 			free(user_input);
// 			break;
// 		}
// 		else
// 		{
// 			fork_id = fork();
// 			if (fork_id == -1)
// 				return(perror("main.c @ line 37 "), EXIT_FAILURE);
// 			if (fork_id == 0)
// 			{
// 				argument = ft_split(user_input, ' ');
// 				exec_command(argument[0], argument, envp);
// 			}
// 			else
//                 waitpid(fork_id, &status, 0);
// 			free(user_input);
// 		}
// 	}
// 	return (0);
// }

//[Debug] test envp function
int main(int argc, char **argv, char *envp[])
{
	if (argc != 1 || !argv[0])
		return(perror("main.c @ line 19 "), EXIT_FAILURE);
	t_envp_list	*envp_list;

	envp_list = NULL;
	
	//[TODO] test error handling, malloc == null, valgring, fsanitize
	fill_envp_list(&envp_list, envp);
	display_envp_list(&envp_list);
}
