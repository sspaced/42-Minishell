/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/07/31 02:24:08 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/minishell.h"

//[BUG] With "exit" need to type 2 time to work.
// int	main(int argc, char **argv, char *envp[])
// {
// 	int fork_id;
// 	char *user_input;
// 	char **argument;
// 	int status;
// 	t_envp_list	*envp_list;
	
// 	envp_list = NULL;
	
// 	if (argc != 1 || !argv[0])
// 		return(perror("main.c @ line 26 "), EXIT_FAILURE);
// 	if (!fill_envp_list(&envp_list, envp))
// 		return(perror("main.c @ line 28 "), envp_list_clear(&envp_list), EXIT_FAILURE);
// 	while (1)
// 	{
// 		user_input = readline("minishell$ ");
// 		if (user_input != NULL)
// 			add_history(user_input);
// 		if (ft_strlen(user_input) == 4 && !ft_strncmp("exit", user_input, 4))
// 		{
// 			printf("exit\n");
// 			free(user_input);
// 			exit(errno);
// 		}
// 		else if (ft_strlen(user_input) == 3 && !ft_strncmp("env", user_input, 3))
// 		{
// 			display_envp(&envp_list);
// 			free(user_input);
// 		}
// 		else if (ft_strlen(user_input) >= 6 && !ft_strncmp("export", user_input, 6))
// 		{
// 			export_envp(&envp_list, user_input);
// 			free(user_input);
// 		}
// 		else if (ft_strlen(user_input) >= 5 && !ft_strncmp("unset", user_input, 5))
// 		{
// 			unset_envp(&envp_list, user_input);
// 			free(user_input);
// 		}
// 		else if (ft_strlen(user_input) >= 2 && !ft_strncmp("cd", user_input, 2))
// 		{
// 			change_directory(user_input);
// 			free(user_input);
// 		}
// 		else
// 		{
// 			fork_id = fork();
// 			if (fork_id == -1)
// 				return(perror("main.c @ line 37 "), EXIT_FAILURE);
// 			if (fork_id == 0)
// 			{
// 				argument = ft_split(user_input, ' ');
// 				exec_command_v2(argument[0], argument, &envp_list);
// 			}
// 			else
//                 waitpid(fork_id, &status, 0);
// 			free(user_input);
// 		}
// 	}
// 	return (0);
// }

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
		
// 	// display_envp(&envp_list);
// 	// printf("\n\n\n");
// 	// while(*envp)
// 	// {
// 	// 	printf("%s\n", *envp);
// 	// 	envp++;
// 	// }
// 	char *arg = "pwd";
// 	char **option = ft_split(arg, ' ');
// 	exec_command_v2("pwd", option, &envp_list, envp);
// 	// clear_array(option);
	
// 	// export_envp(&envp_list, "export ke=value");
// 	// display_envp(&envp_list);
// 	// export_envp(&envp_list, "export key=value");
// 	// unset_envp(&envp_list, "unset ke");
// 	// display_envp(&envp_list);
// 	envp_list_clear(&envp_list);
// }

// [Debug] Pipe
// int	main(int argc, char **argv, char *envp[])
// {
// 	char		***commands;
// 	char		**envp_local;
// 	t_envp_list	*envp_list;
// 	int			 **fd_tab;

// 	envp_list = NULL;
// 	if (!fill_envp_list(&envp_list, envp))
// 		return(perror("main.c @ line 28 "), envp_list_clear(&envp_list), EXIT_FAILURE);

// 	commands = create_command(argv);
// 	launch_pipe(commands, &envp_list);
// 	// while(*commands)
// 	// {
// 	// 	printf("Command : %s, option : %s\n", (*commands)[0], (*commands)[1]);
// 	// 	commands++;
// 	// }
	
// 	// pipe(pipe_fd);
	
// 	// fork_id = fork();
// 	// if (fork_id == 0)
// 	// {
// 	// 	close(pipe_fd[0]);
//     //     dup2(pipe_fd[1], STDOUT_FILENO);
//     //     close(pipe_fd[1]);
		
// 	// 	if (!exec_command_v2(cmd1[0], cmd1, &envp_list, envp))
// 	// 		printf("failed\n");
// 	// }
// 	// else
// 	// {
// 	// 	fork_id_2 = fork();
// 	// 	if (fork_id_2 == 0)
// 	// 	{
// 	// 		close(pipe_fd[1]);
//     //         dup2(pipe_fd[0], STDIN_FILENO);
//     //         close(pipe_fd[0]); 
			
// 	// 		if (!exec_command_v2(cmd2[0], cmd2, &envp_list, envp))
// 	// 			printf("failed2\n");
// 	// 	}
// 	// 	close(pipe_fd[0]);
//     //     close(pipe_fd[1]);
//     //     waitpid(fork_id, &status, 0);
//     //     waitpid(fork_id_2, &status, 0);
// 	// }
// 	// launch_pipe(argv);
// 	return (0);
// }

// void sig_handler(int sig)
// {
// 	if (sig == SIGINT)
// 		write(1, "\n", 1);
// 	if (sig == SIGQUIT)
// 		write(1, "exit", 4);
// }

//[Debug] Signal
// int main()
// {
// 	struct buffer[256];
	
// 	sigemptyset(&act.sa_mask);
	
// 	act.sa_flags = SA_SIGINFO;
// 	act.sa_handler = &sig_handler;
// 	if (sigaction(SIGINT, &act, NULL) == -1)
// 		return (1);
// 	if (sigaction(SIGQUIT, &act, NULL) == -1)
// 		return (1);
// 	pid = getpid();
// 	ft_putstr_fd("Server PID is ", 1);
// 	ft_putnbr_fd(pid, 1);
// 	ft_putchar_fd('\n', 1);
// 	while (1)
// 	{
// 		 if (fgets(buffer, sizeof(buffer), stdin) == NULL)
// 		 {
// 			write(1, "exit", 4);
// 			exit(EXIT_SUCCESS);
// 		 }
		 
// 	}
// 	return (0);
// }


//[DEBUG] add_history 
// int main (void)
// {
// 	char	*user_input;
// 	int		history_file;
	
// 	history_file = open("./history/history.txt", O_RDWR);
// 	if (!history_file)
// 		printf("err opening file\n");
// 	load_history(history_file);
// 	while(1)
// 	{
// 		user_input = readline("minishell$ ");
// 		add_history_custom(user_input, history_file);
// 	}
// 	close(history_file);
// 	return (0);
// }

//[["type", "value"], ["type", "value"], ["type", "value"]]

// char **
// char *** command_array;

// command_array = malloc(nb_command * sizeof(char **));

// void check_builtins(char ***commands)
// {
	
// }

//[DEBUG] check_builtins
// int main(void)
// {
// 	char *commands_string = "0 ls, 1 cat , type value";
// 	char **splited_command_string;
// 	char **command;
// 	char ***commands;
// 	int index;
// 	int command_nb;
	
// 	splited_command_string = ft_split(commands_string, ',');
// 	command_nb = 3;
// 	commands = malloc(command_nb * sizeof(char **));
// 	index = 0;
// 	while (index < command_nb)
// 	{
// 		command = ft_split(splited_command_string[index], ' ');
// 		commands[index] = command;
// 		index++;	
// 	}
// 	printf("commands[2][0] : %s\n", commands[2][0]);
// 	return (0);
// }

int commands_size(t_input *tokens)
{
	int size;

	size = 0;
	while (tokens)
	{
		if (tokens->type == PIPE)
			size++;
		tokens = tokens->next;
	}
	return (size);
}

// void convert_to_commands(t_input *tokens)
// {
	
// }

//[DEBUG] parser impl
int main(void)
{
	char	*user_input;
	t_input *tokens = NULL;
	
	while(1)
	{
		user_input = readline("minishell$ ");
        tokenize_input(user_input, &tokens);
		printf("%d %p\n", commands_size(tokens), tokens);
		//print_tokens(tokens);
		// while (tokens)
    	// {
        // 	printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
        // 	tokens = tokens->next;
    	// }
	}
	return (0);
}
