/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:37:12 by root              #+#    #+#             */
/*   Updated: 2024/06/07 16:57:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*envp_list_get(t_envp_list **envp_list, char *key)
{
	size_t		key_len;
	char		*value;
	t_envp_list *envp_next;
	t_envp_list *envp_head;
	
	if (!envp_list)
		return (NULL);
	key_len = ft_strlen(key);
	value = NULL;
	envp_head = *envp_list;
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		if (!ft_strncmp(key, (*envp_list)->key, key_len))
			value  = (*envp_list)->value;
		*envp_list = envp_next;
	}
	*envp_list = envp_head;
	return (value);
}

//[SECURED]
int	envp_list_add(t_envp_list **envp_list, char *key, char *value)
{
	char		*key_dup;
	char		*value_dup;
	t_envp_list	*envp_node;
	
	if (!envp_list)
		return (0);
	key_dup = ft_strdup(key);
	if (!key_dup)
		return (0);
	value_dup = ft_strdup(value);
	if (!value_dup)
		return (free(key_dup), 0);
	envp_node = envp_list_create_node(key_dup, value_dup);
	if (!envp_node)
		return (free(key_dup), free(value_dup), 0);
	list_add_back(envp_list, envp_node);
	return (1);
}

//[TODO] test security
int	envp_list_del(t_envp_list **envp_list, char *key)
{
	size_t		key_len;
	t_envp_list	*envp_next;
	t_envp_list	*envp_previous;
	t_envp_list	*envp_current;
	t_envp_list	*envp_head;
	
	if (!envp_list)
		return (0);
	key_len = ft_strlen(key);
	envp_head = *envp_list;
	envp_previous = NULL;
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		if (!ft_strncmp(key, (*envp_list)->key, key_len))
		{
			if (!envp_previous)
				envp_head = envp_next;
			else
				envp_previous->next = envp_next;
			if ((*envp_list)->key != NULL)
				free((*envp_list)->key);
			if ((*envp_list)->value != NULL)
				free((*envp_list)->value);
			envp_current = *envp_list;
			free(*envp_list);
		}
		envp_previous = *envp_list;
		*envp_list = envp_next;
	}
	*envp_list = envp_head;
	return (1);
}
