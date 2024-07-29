/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:11:25 by loic              #+#    #+#             */
/*   Updated: 2023/11/27 19:47:13 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = i;
		k = 0;
		while (needle[k] != '\0' && needle[k] == haystack[j] && j < len)
		{
			k++;
			j++;
		}
		if (needle[k] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *haystack = NULL;
//     const char *needle = "le";
//     size_t len = 17 * sizeof(char);

//     printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//     printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//     return (0);
// }
