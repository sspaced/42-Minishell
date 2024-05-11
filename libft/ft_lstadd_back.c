/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:43:31 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:24:25 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		add = ft_lstlast(*lst);
		(*add).next = new;
	}
	else
		*lst = new;
}

// int	main(void)
// {
// 	char	*str = "Hello le world";
// 	char	*str_1 = "test";
// 	char	*str_2 = "pops";
// 	char	*str_3 = "fin";

// 	t_list	*list_element = ft_lstnew(str);
// 	t_list	*list_element_1 = ft_lstnew(str_1);
// 	t_list	*list_element_2 = ft_lstnew(str_2);
// 	t_list	*list_element_3 = ft_lstnew(str_3);
// 	t_list	**list = &list_element;

// 	//printf("%s\n", (char *)(*list_element).content);
// 	ft_lstadd_front(list, list_element_1);
// 	ft_lstadd_front(list, list_element_2);
// 	//printf("%s", (char *)(*(**list).next).content);
// 	ft_lstadd_back(list, list_element_3);
// 	printf("%s\n", (char *)(*ft_lstlast(*list)).content);
// 	return (0);
// }
