/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:31:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/13 09:51:50 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newdlst;

	if (!lst || !f)
		return (NULL);
	newdlst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->data));
		if (!new)
		{
			ft_lstclear(&newdlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newdlst, new);
		lst = lst->next;
	}
	return (newdlst);
}
