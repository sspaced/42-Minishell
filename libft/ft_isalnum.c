/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:14:30 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/21 23:49:52 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c <= 57 && c >= 48) || ((c <= 90 && c >= 65) || (c <= 122 && c >= 97)))
	{
		return (8);
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('A'));
// 	printf("%d\n", ft_isalnum('Z'));
// 	printf("%d\n", ft_isalnum('a'));
// 	printf("%d\n", ft_isalnum('z'));
// 	printf("%d\n", ft_isalnum('1'));
// 	printf("%d\n", ft_isalnum('9'));
// 	printf("%d\n", isalnum('A'));
// 	printf("%d\n", isalnum('Z'));
// 	printf("%d\n", isalnum('a'));
// 	printf("%d\n", isalnum('z'));
// 	printf("%d\n", isalnum('1'));
// 	printf("%d\n", isalnum('9'));
// 	return (0);
// }
