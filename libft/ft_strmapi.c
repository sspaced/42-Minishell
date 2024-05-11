/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:57:50 by loic              #+#    #+#             */
/*   Updated: 2023/11/20 19:11:50 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// static char	f(unsigned int lower, char c)
// {
// 	if (lower == 0)
// 		return ((char)ft_tolower(c));
// 	else
// 		return ((char)ft_toupper(c));
// }
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	char	*str_b;
	size_t	i;

	str_len = ft_strlen(s);
	i = 0;
	if (str_len == 0)
	{
		str_b = (char *)malloc(1);
		if (!str_b)
			return (NULL);
		*str_b = '\0';
		return (str_b);
	}
	str_b = (char *)malloc(str_len + 1);
	if (!str_b)
		return (NULL);
	while (*s)
	{
		*str_b++ = (*f)(i, *s++);
		i++;
	}
	*str_b = '\0';
	return (str_b - str_len);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("Hello LE WORlD", f));
// 	return (0);
// }