/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:45:51 by root              #+#    #+#             */
/*   Updated: 2024/06/07 12:55:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

size_t	str_len_until(char	*str, char	until_char)
{
	size_t counter;

	counter = 0;
	while(str[counter] && str[counter] != until_char)
	{
		counter++;
	}
	return (counter);
}