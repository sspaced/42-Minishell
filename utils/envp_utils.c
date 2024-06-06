/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:44:46 by root              #+#    #+#             */
/*   Updated: 2024/06/06 23:34:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_envp_list	*create_node(char	*key, char	*value)
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

// void	clear_list(t_envp	**envp_list)
// {
	
// }

size_t	strlen_until(char	*str, char	until_char)
{
	size_t counter;

	counter = 0;
	while(str[counter] && str[counter] != until_char)
	{
		counter++;
	}
	return (counter);
}

char	**extract_key_value(char *envp_line)
{
	char	**key_value;
	size_t		key_len;
	size_t		value_len;

	key_value = malloc(2 * sizeof(char *));
	if (!key_value)
		return (NULL);
	key_len = strlen_until(envp_line, '=');
	value_len = ft_strlen(envp_line + key_len);
	key_value[0] = ft_substr(envp_line, 0, key_len);
	if (!key_value[0])
		return (NULL);
	key_value[1] = ft_substr(envp_line, key_len + 1, value_len - 1);
	if (!key_value[1])
		return (NULL);
	return (key_value);
}

int	fill_envp_list(t_envp_list **envp_list, char **envp)
{
	int		counter;
	char	**key_value;
	t_envp_list	*envp_node;
	
	if (!envp)
		return (0);
	counter = 0;
	while (envp[counter])
	{
		key_value = extract_key_value(envp[counter]);
		envp_node = create_node(key_value[0], key_value[1]);
		//[TODO] add a function that clear envp_list if create_node fail
		if (!envp_node)
			return (0);
		lstadd_back(envp_list, envp_node);
		counter++;
	}
	return (1);
}

void	lstadd_back(t_envp_list **lst, t_envp_list *new)
{
	t_envp_list	*add;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		add = lstlast(*lst);
		(*add).next = new;
	}
	else
		*lst = new;
}

t_envp_list	*lstlast(t_envp_list *lst)
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

void	display_envp_list(t_envp_list **envp_list)
{
	t_envp_list	*envp_next;
	
	while (*envp_list)
	{
		envp_next = (*envp_list)->next;
		printf("%s = %s\n", (*envp_list)->key, (*envp_list)->value);
		*envp_list = envp_next;
	}
}