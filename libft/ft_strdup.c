/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:49:05 by loic              #+#    #+#             */
/*   Updated: 2023/11/20 14:56:35 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_b;
	int		str_len;

	str_len = ft_strlen((char *)str);
	str_b = (char *)malloc(str_len * sizeof(char) + 1);
	if (!str_b)
		return (NULL);
	while (*str)
		*str_b++ = *str++;
	*str_b = '\0';
	return (str_b -= str_len);
}
/*
int	main(void)
{
	char		*str;
	const char	*src = "Hello le world";

	str = ft_strdup(src);
	printf("%s\n", str);
	return (0);
}*/