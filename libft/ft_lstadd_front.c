/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:07:15 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:24:51 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		(*new).next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	char	*str = "Hello le world";
// 	char	*str_1 = "test";

// 	t_list	*list_element = ft_lstnew(str);
// 	t_list	*list_element_1 = ft_lstnew(str_1);
// 	t_list	**list = &list_element;

// 	printf("%s\n", (char *)(*list_element).content);
// 	ft_lstadd_front(list, list_element_1);
// 	printf("%s", (char *)(*(**list).next).content);
// 	return (0);
// }