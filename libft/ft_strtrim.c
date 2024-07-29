/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:59:06 by loic              #+#    #+#             */
/*   Updated: 2023/11/29 15:53:44 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	is_set(char const c, char const *set)
{
	int	found;

	found = 0;
	while (*set)
	{
		if (*set == c)
		{
			found = 1;
		}
		set++;
	}
	return (found);
}

static size_t	count_forw(char const *s1, char const *set)
{
	size_t	count;

	count = 0;
	while (*s1)
	{
		if (!is_set(*s1, set))
		{
			break ;
		}
		count++;
		s1++;
	}
	return (count);
}

static size_t	count_backw(char const *s1, char const *set, size_t len)
{
	size_t	count;

	count = 0;
	while (len)
	{
		if (!is_set(*s1, set))
		{
			break ;
		}
		count++;
		s1--;
		len--;
	}
	return (count);
}

static char	*fill(char const *s1, char	*str_trimed, size_t len)
{
	size_t	len_buff;

	len_buff = len;
	while (len)
	{
		*str_trimed = *s1;
		str_trimed++;
		s1++;
		len--;
	}
	*str_trimed = '\0';
	return (str_trimed - len_buff);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*str_trimed;

	len = ft_strlen(s1);
	start = count_forw(s1, set);
	end = count_backw(s1 + (len - 1), set, len);
	if (start == len)
	{
		str_trimed = (char *)malloc(1);
		if (!str_trimed)
			return (NULL);
		*str_trimed = '\0';
		return (str_trimed);
	}
	len -= start + end;
	str_trimed = (char *)malloc(len + 1);
	if (!str_trimed)
		return (NULL);
	return (fill(s1 + start, str_trimed, len));
}

// int	main(void)
// {
// 	printf("%s\n",ft_strtrim("Hello", "Ho"));
// 	return (0);
// }