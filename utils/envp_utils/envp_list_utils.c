/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:42:39 by root              #+#    #+#             */
/*   Updated: 2024/06/07 16:32:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	list_add_back(t_envp_list **lst, t_envp_list *new)
{
	t_envp_list	*add;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		add = list_last(*lst);
		(*add).next = new;
	}
	else
		*lst = new;
}

t_envp_list	*list_last(t_envp_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!(*lst).next)
			return (lst);
		lst = (*lst).next;
	}
	return (lst);
}

//[Secured]
t_envp_list	*envp_list_create_node(char	*key, char	*value)
{
	t_envp_list	*new_node;
	new_node = malloc(sizeof(t_envp_list));
	if (!new_node)
		return NULL;
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	envp_list_clear(t_envp_list	**envp_list)
{
	t_envp_list	*envp_next;

	if (!envp_list)
		return ;
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		if ((*envp_list)->key != NULL)
			free((*envp_list)->key);
		if ((*envp_list)->value != NULL)
			free((*envp_list)->value);
		free(*envp_list);
		*envp_list = envp_next;
	}
}
