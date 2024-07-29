/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:10:41 by root              #+#    #+#             */
/*   Updated: 2024/06/23 21:48:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	unset_envp(t_envp_list **envp_list, char *user_input)
{
	char	**splited_input;
	char	**splited_buff;

	splited_input = ft_split(user_input, ' ');
	if (array_len(splited_input) == 2)
		envp_list_del(envp_list, splited_input[1]);
	return (clear_array(splited_input));
}
