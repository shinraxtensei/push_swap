/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:41:35 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/11 08:50:21 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void	sort_3(t_global *tab)
{
	int	arr[3];

	arr[0] = *(int *)tab->head_a->data;
	arr[1] = *(int *)tab->head_a->next->data;
	arr[2] = *(int *)tab->head_a->next->next->data;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		sa(tab, 1);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		sa(tab, 1);
		rra(tab, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ra(tab, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		sa(tab, 1);
		ra(tab, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rra(tab, 1);
}

static void	sort_5(t_global *tab, int nbrs_count)
{
	if (nbrs_count == 5)
		pb(tab, 1);
	pb(tab, 1);
	sort_3(tab);
	if (nbrs_count == 5)
		smart_push(tab);
	smart_push(tab);
	sort_a(tab);
}

void	small_sort(t_global *tab, int nbrs_count)
{
	if (tab->a_sz == 2)
	{
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->data)
			sa(tab, 1);
	}
	else if (tab->a_sz == 3)
		sort_3(tab);
	else
		sort_5(tab, nbrs_count);
}
