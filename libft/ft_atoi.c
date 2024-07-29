/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:07 by loic              #+#    #+#             */
/*   Updated: 2023/11/29 15:40:52 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static const char	*ft_white_space(const char *str)
{
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	size_t	sign;
	long	nb;

	nb = 0;
	sign = 0;
	str = ft_white_space(str);
	if (*str == '-')
	{
		sign++;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (((nb * 10) + (*str - 48)) / 10 != nb)
			return (LONG_MIN * (sign > 0) + LONG_MAX * (sign == 0));
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	if (sign == 1)
		return (-nb);
	if (sign > 1)
		return (0);
	return ((int)nb);
}
/*
int	main(void)
{
	char *test = "   \t\n -113534659223372036854775807";
	int vrai = atoi("   \t\n -113534659223372036854775807");
	int ok = ft_atoi(test);
	printf("celui de base : %d\n", vrai);
	printf("mine : %d\n", ok);
	return(0);
}*/
