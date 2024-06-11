/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:44:03 by root              #+#    #+#             */
/*   Updated: 2024/06/12 00:14:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	display_envp(t_envp_list **envp_list)
{
	t_envp_list	*envp_next;
	t_envp_list	*envp_head;

	if (!envp_list)
		return ;
	envp_head = *envp_list;
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		printf("%s = %s\n", (*envp_list)->key, (*envp_list)->value);
		*envp_list = envp_next;
	}
	*envp_list = envp_head;
}
