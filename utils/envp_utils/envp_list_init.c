/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:36:03 by root              #+#    #+#             */
/*   Updated: 2024/06/27 21:52:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//[SECURED]
//[COMMENT] Duplicate envp in a link list.
int	fill_envp_list(t_envp_list **envp_list, char **envp)
{
	int			counter;
	char		**key_value;
	t_envp_list	*envp_node;

	if (!envp)
		return (0);
	counter = 0;
	while (envp[counter])
	{
		key_value = extract_key_value(envp[counter]);
		if (!key_value)
			return (0);
		envp_node = envp_list_create_node(key_value[0], key_value[1]);
		if (!envp_node)
			return (free(key_value[0]), free(key_value[1]), free(key_value), 0);
		free(key_value);
		list_add_back(envp_list, envp_node);
		counter++;
	}
	return (1);
}

//[TODO] tested key_value[0] and key_value[1] == NULL, 
		// need to test if malloc fail at n iteration.
//[COMMENT] Extract key/value pair from envp.
char	**extract_key_value(char *envp_line)
{
	char		**key_value;
	size_t		key_len;
	size_t		value_len;

	key_value = malloc(2 * sizeof(char *));
	if (!key_value)
		return (NULL);
	key_len = str_len_until(envp_line, '=');
	value_len = ft_strlen(envp_line + key_len);
	key_value[0] = ft_substr(envp_line, 0, key_len);
	if (!key_value[0])
		return (free(key_value), NULL);
	key_value[1] = ft_substr(envp_line, key_len + 1, value_len - 1);
	if (!key_value[1])
		return (free(key_value[0]), free(key_value), NULL);
	return (key_value);
}
