/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:14:01 by loic              #+#    #+#             */
/*   Updated: 2023/11/20 18:08:51 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static long	ft_count(long n)
{
	long	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

static char	*ft_createtab(long n, long count, int negatif, char	*s)
{
	if (n != 0)
	{
		s = (char *)malloc(sizeof(char) * count + 1);
		if (s == NULL)
			return (NULL);
	}
	else
		return (ft_strdup("0"));
	if (n < 0)
	{
		negatif = 1;
		n *= -1;
	}
	s[count] = '\0';
	while (--count)
	{
		s[count] = (n % 10) + '0';
		n /= 10;
	}
	if (negatif == 1)
		s[0] = '-';
	else
		s[0] = (n % 10) + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	long	count;
	long	nb;
	char	*s;
	int		negatif;

	negatif = 0;
	nb = n;
	s = NULL;
	count = ft_count(nb);
	s = ft_createtab(nb, count, negatif, s);
	return (s);
}

/*
int	main(void)
{
	char *test = ft_itoa(-2147483649);
	printf("%s", test);
	return (0);
} */