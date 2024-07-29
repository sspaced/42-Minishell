/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:11:46 by lben-adi          #+#    #+#             */
/*   Updated: 2024/07/16 22:18:25 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*strdup_until(const char *str, char until_char)
{
	char	*str_b;
	int		str_len;
	int		index;

	index = 0;
	str_len = str_len_until((char *)str, until_char);
	if (!str_len)
		return (NULL);
	str_b = (char *)malloc(str_len * sizeof(char) + 1);
	if (!str_b)
		return (NULL);
	while (index < str_len)
	{
		*str_b++ = *str++;
		index++;	
	}
	*str_b = '\0';
	return (str_b -= str_len);
}

//[SECURED]
int	load_history(int history_file)
{
	char *raw_line;
	char *history_line;
	int		status;
	
	status = 1;
	while (status)
	{
		raw_line = get_next_line(history_file);
		if (!raw_line)
			return (0);
		history_line = strdup_until(raw_line, '\n');
		if (!history_line)
			return (free(raw_line), 0);
		add_history(history_line);
		free(raw_line);
		free(history_line);
	}
	return (0);
}

int add_history_custom(char *user_input, int history_file)
{
	char	*history_input;
	int		history_input_len;
	
	if (user_input != NULL && !(ft_strlen(user_input) < 1))
	{
		add_history(user_input);
		history_input = ft_strjoin(user_input, "\n");
		if (!history_input)
			return (0);
		history_input_len = ft_strlen(history_input);
		write(history_file, history_input, history_input_len);
		free(history_input);
	}
	return (1);
}
