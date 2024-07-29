/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:41 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:32:54 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	if (!lst)
		return (0);
	while (temp)
	{
		temp = (*temp).next;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	char	*str = "Hello le world";
	char	*str_1 = "test";
	char	*str_2 = "pops";

	t_list	*list_element = ft_lstnew(str);
	t_list	*list_element_1 = ft_lstnew(str_1);
	t_list	*list_element_2 = ft_lstnew(str_2);
	t_list	**list = &list_element;

	//printf("%s\n", (char *)(*list_element).content);
	ft_lstadd_front(list, list_element_1);
	ft_lstadd_front(list, list_element_2);
	//printf("%s", (char *)(*(**list).next).content);

	printf("%d\n", ft_lstsize(*list));
	return (0);
} */