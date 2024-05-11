/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:12:01 by loic              #+#    #+#             */
/*   Updated: 2023/11/24 14:20:42 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}
/*
int main(void)
{
    const char *str = "Hello world";
    int c = 'w';
    char *res_true;
    char *res_fake;

    res_fake = ft_strchr(str, c);
    res_true = strchr(str, c);
    printf("%s\n", res_fake);
    printf("%s\n", res_true);
    return (0);
}
*/
