/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:52:11 by loic              #+#    #+#             */
/*   Updated: 2023/11/28 14:41:59 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *mem, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(const unsigned char *)(mem + i) == (const unsigned char)c)
			return ((void *)(mem + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str_fake = "Hello world";
	const char	*str_true = "Hello world";
	int			c;
	size_t		size;

	c = 'p';
	size = 5 * sizeof(char);
	printf("%s\n", ft_memchr(str_fake, c, size));
	printf("%s\n", memchr(str_true, c, size));
	return (0);
}
*/
