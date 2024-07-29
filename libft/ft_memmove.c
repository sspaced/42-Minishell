/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:55 by loic              #+#    #+#             */
/*   Updated: 2023/11/20 18:59:33 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cdest;
	const char	*csrc;

	i = n;
	if (!src && !dest)
		return (NULL);
	cdest = dest;
	csrc = src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dest);
}
// int main(void)
// {
//     char src[] = "abcdefghijklmnopqrstuvwxyz";
//     char src2[] = "abcdefghijklmnopqrstuvwxyz";
//     char *ptr;
//     char *ptr1;

//     printf("%s\n", src);
//     ptr = memmove(src + 5, src, 9);
//     ptr1 = ft_memmove_trash(src2 + 5, src2, 9);
//     printf("%s\n", ptr);
//     printf("%s\n", ptr1);

//     return (0);
// }