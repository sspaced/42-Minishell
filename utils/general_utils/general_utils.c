/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:51 by root              #+#    #+#             */
/*   Updated: 2024/07/15 21:00:41 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//[COMMENT] Count char until it encounter a specific char.
size_t	str_len_until(char *str, char until_char)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
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

void clear_int_array(int **array, int len)
{
	int index;

	index = 0;
	while(index < len)
	{
		if (array[index] != NULL)
			free(array[index]);
		index++;
	}
	free(array);
}
