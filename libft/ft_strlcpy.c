/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:42 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/20 19:16:18 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (size != 0)
	{
		while (*src && (size - 1))
		{
			*dst = *src;
			dst++;
			src++;
			size--;
		}
		*dst = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
    const char *src = "Hello le world";
    char dst[6];
    size_t size = 0 * sizeof(char);

    printf("%zu\n", ft_strlcpy(dst, src, size));
    printf("%s\n", dst);
    return (0);
}
*/