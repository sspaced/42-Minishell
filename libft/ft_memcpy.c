/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:03 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/27 19:32:53 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		j;
	const char	*temp_src;
	char		*temp_dest;

	temp_src = src;
	temp_dest = dest;
	j = 0;
	if (!dest && !src)
		return (NULL);
	while (j < n)
	{
		temp_dest[j] = temp_src[j];
		j++;
	}
	return (dest);
}

/*
int main(void)
{
    const char src[11] = "hello";
    char dest[1];
    char t_dest[1];
    size_t size = 5*sizeof(char);
    ft_memcpy(dest, src, size);
    memcpy(t_dest, src, size);
    printf("%s\n", dest);
    printf("%s\n", t_dest);
    return (0);
}
*/
