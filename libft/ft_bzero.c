/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:34:59 by loic              #+#    #+#             */
/*   Updated: 2023/11/13 18:40:26 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *p, size_t size)
{
	char	*new_p;

	new_p = p;
	while (size)
	{
		*new_p = 0;
		new_p++;
		size--;
	}
}
/*
int main(void)
{
    char str[6] = "hello";
    char str_bis[6] = "hello";

    ft_bzero(str + 2, 1 * sizeof(char));
    bzero(str_bis + 2, 1 * sizeof(char));

    printf("%s\n", str);
    printf("%s\n", str_bis);
    return (0);
}
*/
