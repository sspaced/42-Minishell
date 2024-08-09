/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:42 by loic              #+#    #+#             */
/*   Updated: 2024/08/09 17:28:11 by root             ###   ########.fr       */
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

// int pipe_nb(t_input *tokens)
// {
// 	int size;

// 	size = 0;
// 	while (tokens)
// 	{
// 		if (tokens->type == PIPE)
// 			size++;
// 		tokens = tokens->next;
// 	}
// 	return (size);
// }

// void convert_to_commands(t_input *tokens)
// {
	
// }

//[DEBUG] parser impl
// int main(void)
// {
// 	char	*user_input;
// 	t_input *tokens = NULL;
	
// 	while(1)
// 	{
// 		user_input = readline("minishell$ ");
//         tokenize_input(user_input, &tokens);
// 		//print_tokens(tokens);
// 		while (tokens)
//     	{
//         	printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
//         	tokens = tokens->next;
//     	}
// 	}
// 	return (0);
// }

//[DEBUG] redirection
// int main(int argc, char **argv, char *envp[])
// {
// 	// redirection_type 1 : >>, 2 : >, 3 : <
// 	t_envp_list	*envp_list = NULL;
// 	//char *command[] = {"cat", ""};
// 	char *file_name = "output.txt";
// 	int redirection_type = 1;
// 	int fd_1 = 1;
// 	int fd_2;

// 	if (!fill_envp_list(&envp_list, envp))
// 		return(perror("main.c @ line 28 "), envp_list_clear(&envp_list), EXIT_FAILURE);
// 	redirect_input(file_name, 0);
// 	//redirect_output(file_name, 1, 2);
// 	if (!exec_command_v2(argv[1], argv + 1, &envp_list))
// 		write(2, "failed", 6);
// 	return (0);
// }

// int is_redirection(char *str)
// {
// 	int i;
// 	int is_redirection;

// 	i = 0;
// 	is_redirection = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '<' || str[i] == '>')
// 		{
// 			is_redirection += 1;
// 			if ((str[i + 1] != '\0' ) && (str[i + 1] == '>'))
// 			{
// 				if ((str[i + 2] != '\0') && (str[i + 2] == '>'))
// 					return (0);
// 				else
// 					return (is_redirection);
// 			}
// 			else if ((str[(i + 1)] != '\0') && (str[i + 1] == '<'))
// 				return (0);	
// 		}
// 		i++;
// 	}
// 	if (is_redirection > 1)
// 		return (0);
// 	return (is_redirection);
// }

int is_redirection(char *str)
{
	int i;
	int grt;
	int srt;

	i = 0;
	grt = 0;
	srt = 0;
	
	while(str[i])
	{
		if (str[i] == '<')
			srt++;
		if (str[i] == '>')
			grt++;
		i++;
	}
	if (srt == 1 && grt == 0)
		return (1);
	if (grt == 1 && srt == 0)
		return (2);
	if (grt == 2 && srt == 0)
		return (3);
	return (0);
}

void set_fd1_first(char *redirection_index, t_redirection *redirection)
{
	if (is_redirection(redirection_index) == 1)
	{
		redirection->fd1 = "0";
		redirection->redirection_type = 1;	
	}
	else
	{
		redirection->fd1 = "1";
		redirection->redirection_type = is_redirection(redirection_index);
	}
}
// case where "<"
void extract_no_len(char **splited_instruction, int index_redirection, t_redirection *redirection)
{
	// if (is_redirection(splited_instruction[index_redirection]) == 1)
	// {
	// 	redirection->fd1 = "0";
	// 	redirection->redirection_type = 1;	
	// }
	// else
	// {
	// 	redirection->fd1 = "1";
	// 	redirection->redirection_type = is_redirection(splited_instruction[index_redirection]);
	// }
	set_fd1_first(splited_instruction[index_redirection], redirection);
	if (splited_instruction[index_redirection + 1] != NULL)
		redirection->fd2 = splited_instruction[index_redirection + 1];
	else
		redirection->fd2 = NULL;
}

int extract_len_validity(char *redirection_index)
{
	int i;
	int redirection;

	i = 0;
	redirection = 0;
	while(redirection_index[i])
	{
		if (redirection_index[i] == '<' || redirection_index[i] == '>')
			redirection++;
		if (ft_isdigit(redirection_index[i]) == 0 && redirection == 0)
			return (0);
		i++;
	}
	return (1);
}

int extract_len_is_first(char *redirection_index)
{
	if (redirection_index[0] == '<' || redirection_index[0] == '>')
		return (1);
	else
		return (0);
}

void set_redirection(char *fd1, char *fd2, int redirection_type, t_redirection *redirection)
{
		redirection->fd1 = fd1;
		redirection->fd2 = fd2;
		redirection->redirection_type = redirection_type;
}

//case where "<2"
void extract_len(char **splited_instruction, int index_redirection, t_redirection *redirection)
{
	char **s_splited_instruction;
	int redirection_type;

	redirection_type = is_redirection(splited_instruction[index_redirection]);
	
	if (!extract_len_validity(splited_instruction[index_redirection]))
		set_redirection(NULL, NULL, redirection_type, redirection);
	else
	{
		if (redirection_type == 1)
			s_splited_instruction = ft_split(splited_instruction[index_redirection], '<');
		else
			s_splited_instruction = ft_split(splited_instruction[index_redirection], '>');
		if (array_len(s_splited_instruction) == 1)
		{
			if (extract_len_is_first(splited_instruction[index_redirection]))
			{
				set_fd1_first(splited_instruction[index_redirection], redirection);
				redirection->fd2 = s_splited_instruction[0];
			}
			else
			{
				if (splited_instruction[index_redirection + 1] != NULL)
					set_redirection(s_splited_instruction[0], splited_instruction[index_redirection + 1], redirection_type, redirection);
				else
					set_redirection(s_splited_instruction[0], NULL, redirection_type, redirection);
			}
		}
		else
			set_redirection(s_splited_instruction[0], s_splited_instruction[1], redirection_type, redirection);
	}
}

void extract_redirection(char **splited_instruction, t_redirection *redirection)
{
	int i;
	int redirection_type;
	
	i = 0;
	redirection_type = 0;
	while (splited_instruction[i])
	{
		redirection_type = is_redirection(splited_instruction[i]);
		if (redirection_type != 0)
		{
			if ((redirection_type == 3 && ft_strlen(splited_instruction[i]) == 2) || (redirection_type != 3 && ft_strlen(splited_instruction[i]) == 1))
				extract_no_len(splited_instruction, i, redirection);
			else
				extract_len(splited_instruction, i, redirection);
		}
		i++;
	}
}

char **extract_words(char **splited_instruction, int mode)
{
	int i;

	i = 0; 
	if (mode == 0)
	{
		// redirection yes
		while()
	}
	else
	{
		// redirection no
	}
	
	return (NULL);
}

void parse_instruction(char **instruction_array)
{
	int i;
	char **splited_instruction;
	char **words;
	t_redirection redirection;

	i = 0;
	while (instruction_array[i])
	{
		if (is_redirection(instruction_array[i]) != 0)
		{
			splited_instruction = ft_split(instruction_array[i], ' ');
			extract_redirection(splited_instruction, &redirection);
			printf("fd1 = %s, fd2 = %s, redirection type : %d\n", redirection.fd1, redirection.fd2, redirection.redirection_type);
			//extract_words
			//add node with redirection and words
		}
		else
		{
				//set redirection to NULL
				//extract_words
				//add node with redirection and words
		}
		i++;
	}
}
void display_array(char **array)
{
	int i = 0;
	
	while(array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
//[TEST] New parsing implem idea
int main(void)
{
	char *user_input;
	char **splited_user_input;

	while(1)
	{
		user_input = readline("minishell$ ");
		// Pre group
		splited_user_input = ft_split(user_input, '|');
		parse_instruction(splited_user_input);	
		//parse_word();
	}
	
	// char *test_no_len[3] = {"<", "1 <", "1 < 2", "", NULL};
	// char *test_len[3] = {"2<1", "test", NULL};
	// int i = 0;

	// while(test_redirection[i])
	// {
	// 	printf("%s\n", test_redirection[i]);
	// 	i++;
	// }
	// if (extract_len_validity(test_redirection))
	// 	printf("valid\n");
	// else
	// 	printf("not valid");
	// if (count_redirection(test_redirection) == 1)
	// 	printf("<\n");
	// if (count_redirection(test_redirection) == 2)
	// 	printf(">\n");
	// if (count_redirection(test_redirection) == 3)
	// 	printf(">>\n");
	// if (count_redirection(test_redirection) == 0)
	// 	printf("No redirection");
	return (0);
}
