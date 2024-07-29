/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:52:50 by lben-adi          #+#    #+#             */
/*   Updated: 2023/11/29 15:25:45 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextn;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nextn = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextn;
	}
	*lst = NULL;
}
