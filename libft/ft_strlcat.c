/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:37 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/27 18:11:37 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	while (dst[i] && i < n)
		i++;
	j = 0;
	tmp = i;
	if (n > i)
	{
		while (src[j] && (j + tmp) < (n - 1))
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	return (j + tmp);
}
/*
int	main(void)
{
	char		dst[] = "hello le";
	const char	*src = " world";
	size_t		size;

	size = 15 * sizeof(char);
	ft_strlcat(dst, src, size);
	printf("%s",dst);
	return (0);
}
*/
