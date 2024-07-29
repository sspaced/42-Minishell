/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:28:51 by loic              #+#    #+#             */
/*   Updated: 2023/11/28 15:07:07 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			last_occurrence = s;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}

/*
int main(void)
{
    const char *str = "Hello world";
    int c = 'o';

    printf("%s\n", ft_strrchr(str, c));
    printf("%s\n", strrchr(str, c));
    return (0);
}
*/
