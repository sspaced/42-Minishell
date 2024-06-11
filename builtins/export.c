/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:16:40 by root              #+#    #+#             */
/*   Updated: 2024/06/12 00:16:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//[SECURED]
//[COMMENT] Extract key/value from user 
			//input and add them to envp linked list.
//[BUG] In bash "export test=test=" give  test=test= in 
		//envp and I get test=test in mine, maybe tom pb.
int	export_envp(t_envp_list **envp_list, char *user_input)
{
	char	**splited_input;
	char	**splited_buff;

	splited_input = ft_split(user_input, ' ');
	if (array_len(splited_input) == 2)
	{
		splited_buff = splited_input;
		splited_input = ft_split(splited_input[1], '=');
		clear_array(splited_buff);
		if (array_len(splited_input) == 2)
		{
			envp_list_add(envp_list, splited_input[0], splited_input[1]);
			return (clear_array(splited_input), 1);
		}
		else
			return (clear_array(splited_input), 0);
	}
	else
		return (clear_array(splited_input), 0);
	return (1);
}
