/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:51 by root              #+#    #+#             */
/*   Updated: 2024/06/26 18:05:13 by root             ###   ########.fr       */
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

//[TEMP]
size_t	array_len_gen(int **array)
{
	size_t	counter;

	if (!array)
		return (0);
	counter = 0;
	while (array[counter])
		counter++;
	return (counter);
}

//[TEMP]
size_t	array_array_len(char ***array)
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
