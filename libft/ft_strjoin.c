/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:34:41 by loic              #+#    #+#             */
/*   Updated: 2023/11/16 18:50:27 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	count;
	char	*str_b;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	count = 0;
	str_b = (char *)malloc((s1_len + s2_len) + 1);
	if (!str_b)
		return (NULL);
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
	return (str_b - count);
}
// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello", ""));
// 	return (0);
// }