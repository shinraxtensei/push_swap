/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:41:39 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/11 08:52:19 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static int	is_sorted(t_list *head)
{
	while (head->next)
	{
		if (*(int *)head->data > *(int *)head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_handler(t_global *tab, int nbrs_count)
{
	if (nbrs_count < 2 || is_sorted(tab->head_a))
		return ;
	if (nbrs_count <= 5)
		small_sort(tab, nbrs_count);
	else
		big_sort(tab);
}
