/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:13 by lben-adi          #+#    #+#             */
/*   Updated: 2024/07/15 20:38:54 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

size_t	ft_strlen_gnl(char const *str, int mode)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	if (mode == 1)
	{
		while (*str != '\0' && *str != '\n')
		{
			str++;
			counter++;
		}
		if (*str == '\0')
			counter--;
	}
	else
	{
		while (*str)
		{
			str++;
			counter++;
		}
	}
	return (counter);
}

// char	*ft_strchr(const char *str, int c)
// {
// 	if (!str)
// 	{
// 		return (NULL);
// 	}
// 	while (*str != (unsigned char)c)
// 		if (!*str++)
// 			return (0);
// 	return ((char *)str);
// }

char	*ft_strjoin_gnl(char const *s1, char const *s2, char *temp_line)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	count;
	char	*str_b;

	s1_len = ft_strlen_gnl(s1, 0);
	s2_len = ft_strlen_gnl(s2, 0);
	count = 0;
	str_b = (char *)malloc((s1_len + s2_len) + 1);
	if (!str_b)
		return (free(temp_line), NULL);
	while (*s1)
	{
		*str_b++ = *s1++;
		s1_len--;
		count++;
	}
	while (*s2)
	{
		*str_b++ = *s2++;
		s2_len--;
		count++;
	}
	*str_b = '\0';
	return (free(temp_line), str_b - count);
}
