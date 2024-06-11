/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:51 by root              #+#    #+#             */
/*   Updated: 2024/06/12 00:21:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//[COMMENT] Count char until it encounter a specific char.
size_t	str_len_until(char *str, char until_char)
{
	size_t	counter;

	counter = 0;
	while (str[counter] && str[counter] != until_char)
		counter++;
	return (counter);
}

//[COMMENT] Count element in an array.
size_t	array_len(char **array)
{
	size_t	counter;

	if (!array)
		return (0);
	counter = 0;
	while (array[counter])
		counter++;
	return (counter);
}

//[COMMENT] Free everything in an array.
void	clear_array(char **array)
{
	size_t	counter;

	if (!array)
		return ;
	counter = 0;
	while (array[counter])
	{
		if (array[counter] != NULL)
			free(array[counter]);
		counter++;
	}
	free (array);
}
