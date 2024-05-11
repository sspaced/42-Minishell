/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:46:45 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/21 23:49:07 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (2048);
	}
	return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = '0';
// 	while (i <= '9')
// 	{
// 		printf("Custom : %d and real one ; %d\n", ft_isdigit(i), isdigit(i));
// 		i++;
// 	}
// 	return (0);
// }
