/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:36:51 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/11 08:36:53 by ahouari          ###   ########.fr       */
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
