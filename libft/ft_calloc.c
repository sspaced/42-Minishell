/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:00:02 by loic              #+#    #+#             */
/*   Updated: 2023/11/29 15:41:14 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	i;

	i = nmemb * size;
	if (i != 0 && (i / nmemb != size || i / size != nmemb))
		return (NULL);
	memory = (char *)malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
