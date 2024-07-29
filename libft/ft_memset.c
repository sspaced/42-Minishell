/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:34:59 by loic              #+#    #+#             */
/*   Updated: 2023/11/13 18:39:02 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *p, int value, size_t size)
{
	char	*new_p;

	new_p = p;
	while (size)
	{
		*new_p = (unsigned char)value;
		new_p++;
		size--;
	}
	return (p);
}
/*
int main(void)
{
    char str[6] = "hello";
    char str_bis[6] = "hello";

    ft_memset(str + 1, '.', 3 * sizeof(char));
    memset(str_bis + 1, '.', 3);
    printf("%s\n", str);
    printf("%s\n", str_bis);
    return (0);
}
*/
