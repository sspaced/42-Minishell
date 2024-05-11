/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:46:50 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:05 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	(*new_list).content = content;
	(*new_list).next = NULL;
	return (new_list);
}

// int	main(void)
// {
// 	char	*str = "Hello le world";
// 	t_list	*list = ft_lstnew(str);
// 	printf("%s", (char *)(*list).content);
// 	return (0);
// }