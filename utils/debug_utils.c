/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:30:18 by root              #+#    #+#             */
/*   Updated: 2024/06/06 20:44:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	debug_display_array(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
	{
		printf("array[%d] = %s\n", counter, array[counter]);
		counter++;
	}
}