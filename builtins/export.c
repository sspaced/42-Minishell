/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:16:40 by root              #+#    #+#             */
/*   Updated: 2024/06/07 15:27:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//[TODO] test security
void	add_node_to_envp(t_envp_list **envp_list, char *key, char *value)
{
	t_envp_list	*envp_node;
	
	envp_node = envp_list_create_node(key, value);
	if (!envp_node)
		return ;
	list_add_back(envp_list, envp_node);
}