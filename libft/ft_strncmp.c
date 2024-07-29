/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:11:50 by loic              #+#    #+#             */
/*   Updated: 2023/11/23 06:37:38 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	while (*str1 == *str2 && size && *str1)
	{
		str1++;
		str2++;
		size--;
	}
	if (size == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)*str1 - (unsigned char)*str2);
	}
}
/*
int main(void)
{
    const char *str1 = "azerty";
    const char *str2 = "azYerty";

    printf("%d\n", ft_strncmp(str1, str2, 3 * sizeof(char)));
    printf("%d\n", strncmp(str1, str2, 3 * sizeof(char)));

    return (0);
}
*/
