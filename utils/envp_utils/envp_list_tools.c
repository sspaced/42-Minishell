/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:37:12 by root              #+#    #+#             */
/*   Updated: 2024/06/27 18:37:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//[COMMENT] Query the value associated to a key.
char	*envp_list_get(t_envp_list **envp_list, char *key)
{
	size_t		key_len;
	char		*value;
	t_envp_list	*envp_next;
	t_envp_list	*envp_head;

	if (!envp_list)
		return (NULL);
	key_len = ft_strlen(key);
	value = NULL;
	envp_head = *envp_list;
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		if (!ft_strncmp(key, (*envp_list)->key, key_len))
			value = (*envp_list)->value;
		*envp_list = envp_next;
	}
	*envp_list = envp_head;
	return (value);
}

//[SECURED]
//[COMMENT] Add new key/value node. 
			// (crush node re write if key already exist)(ex : export)
int	envp_list_add(t_envp_list **envp_list, char *key, char *value)
{
	char		*key_dup;
	char		*value_dup;
	t_envp_list	*envp_node;

	if (!envp_list)
		return (0);
	envp_list_del(envp_list, key);
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
//[COMMENT] Del one key/value pair. (ex : unset)
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
		if (ft_strlen((*envp_list)->key) == key_len)
		{
			if (!ft_strncmp(key, (*envp_list)->key, key_len))
			{
				re_link_node(&envp_previous, &envp_head, &envp_next);
				del_one(*envp_list);
				free(*envp_list);
			}
		}
		envp_previous = *envp_list;
		*envp_list = envp_next;
	}
	*envp_list = envp_head;
	return (1);
}

//[TODO] test security
size_t	envp_len(t_envp_list **envp_list)
{
	t_envp_list	*envp_head;
	t_envp_list	*envp_next;
	size_t counter;
	
	counter = 0;
	envp_head = *envp_list;
	
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		*envp_list = envp_next;
		counter++;
	}
	*envp_list = envp_head;
	return (counter);
}

//[TODO] test security
char *join_key_value(char *key, char *value)
{
	char *key_equal;
	char *key_value;

	key_equal = ft_strjoin(key, " = ");
	key_value = ft_strjoin(key_equal, value);
	return (key_value);
}

//[TODO] test security
char	**envp_linked_to_list(t_envp_list **envp_list)
{
	t_envp_list	*envp_head;
	t_envp_list	*envp_next;
	size_t envp_linked_len;
	size_t counter;
	char **envp;

	counter = 0;
	envp_linked_len = envp_len(envp_list);
	envp_head = *envp_list;
	envp = malloc((envp_linked_len + 1) * sizeof(char *));
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		envp[counter] = join_key_value((*envp_list)->key, (*envp_list)->value);
		*envp_list = envp_next;
		counter++;
	}
	*envp_list = envp_head;
	return (envp);
}
