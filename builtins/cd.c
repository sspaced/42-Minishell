/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:25:51 by root              #+#    #+#             */
/*   Updated: 2024/06/23 22:00:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//[TODO] Test permision on directory etc. 
// 		 Could use rl_on_new_line(), rl_replace_line(), rl_redisplay() to display current directory like bash.
void	change_directory(char *user_input)
{
	char	**splited_input;

	splited_input = ft_split(user_input, ' ');
	if (array_len(splited_input) == 2)
	{
		if (chdir(splited_input[1]) != 0)
			printf("cd : %s: %s\n", splited_input[1], strerror(errno));
	}
	if (array_len(splited_input) == 1)
	{
		if (chdir("/") != 0)
			printf("cd : %s: %s\n", "/", strerror(errno));
	}
}
