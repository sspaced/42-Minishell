/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:55:08 by loic              #+#    #+#             */
/*   Updated: 2023/11/24 14:24:21 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	while (size--)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		++str1;
		++str2;
	}
	return (0);
}

/*
int main(void)
{
    char *str1 = "Hello world";
    char *str2 = "hello world";
    size_t size = 11 * sizeof(char);

    printf("Fake : %d\n", ft_memcmp(str1, str2, size));
    printf("True : %d\n", memcmp(str1, str2, size));
    return (0);
}
*/
