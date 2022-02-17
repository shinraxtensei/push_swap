/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:41:29 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/17 09:33:04 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void	smart_rotate_a(t_global *tab, int n)
{
	if (n > tab->a_sz / 2)
	{
		n = tab->a_sz - n;
		while (n--)
			rra(tab, 1);
	}
	else
		while (n--)
			ra(tab, 1);
}

void	smart_push(t_global *tab)
{
	int	number;
	int	cnt;

	cnt = 0;
	number = *(int *)tab->head_a->data;
	tab->a = tab->head_a;
	while (tab->a)
	{
		if (number >= *(int *)tab->a->data)
			number = *(int *)tab->a->data;
		tab->a = tab->a->next;
	}
	tab->a = tab->head_a;
	while (tab->a)
	{
		if (number == *(int *)tab->a->data)
			break ;
		cnt++;
		tab->a = tab->a->next;
	}
	smart_rotate_a(tab, cnt);
	pb(tab, 1);
}
