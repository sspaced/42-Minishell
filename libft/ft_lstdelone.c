/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:48:56 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:26:17 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	else
	{
		del((*lst).content);
		free(lst);
	}
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