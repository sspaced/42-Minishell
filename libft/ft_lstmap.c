/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:07:19 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:27:51 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*result;
	void	*content;

	if (!lst || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content = f((*lst).content);
		new_list = ft_lstnew(content);
		if (!new_list)
		{
			free(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_list);
		lst = (*lst).next;
	}
	return (result);
}
