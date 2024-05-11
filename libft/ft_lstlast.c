/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:35:58 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:31:30 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!(*lst).next)
			return (lst);
		lst = (*lst).next;
	}
	return (lst);
}

// int	main(void)
// {
// 	char	*str = "Hello le world";
// 	char	*str_1 = "test";
// 	char	*str_2 = "pops";

// 	t_list	*list_element = ft_lstnew(str);
// 	t_list	*list_element_1 = ft_lstnew(str_1);
// 	t_list	*list_element_2 = ft_lstnew(str_2);
// 	t_list	**list = &list_element;

// 	//printf("%s\n", (char *)(*list_element).content);
// 	ft_lstadd_front(list, list_element_1);
// 	ft_lstadd_front(list, list_element_2);
// 	//printf("%s", (char *)(*(**list).next).content);

// 	printf("%s\n", (char *)(*ft_lstlast(*list)).content);
// 	return (0);
// }