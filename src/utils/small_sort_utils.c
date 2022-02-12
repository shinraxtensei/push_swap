/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:41:29 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/11 08:50:58 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	is_min_or_max(t_list *head, t_list *element, int find_min)
{
	if (find_min)
	{
		while (head)
		{
			if (*(int *)head->data < *(int *)element->data)
				return (0);
			head = head->next;
		}
	}
	else
	{
		while (head)
		{
			if (*(int *)head->data > *(int *)element->data)
				return (0);
			head = head->next;
		}
	}
	return (1);
}

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

static int	get_ins_pos(t_list *head, int data)
{
	int	pos;
	int	prev_data;

	pos = 0;
	prev_data = *(int *)ft_lstlast(head)->data;
	while (head && (data > *(int *)head->data || data < prev_data))
	{
		pos++;
		head = head->next;
		prev_data = *(int *)head->prev->data;
	}
	return (pos);
}

void	smart_push(t_global *tab)
{
	if (is_min_or_max(tab->head_a, tab->head_b, 1))
	{
		sort_a(tab);
		pa(tab, 1);
	}
	else if (is_min_or_max(tab->head_a, tab->head_b, 0))
	{
		sort_a(tab);
		pa(tab, 1);
		ra(tab, 1);
	}
	else
	{
		smart_rotate_a(tab,
			get_ins_pos(tab->head_a, *(int *)tab->head_b->data));
		pa(tab, 1);
	}
}

void	sort_a(t_global *tab)
{
	int	cnt;

	cnt = 0;
	tab->a = tab->head_a;
	while (tab->a)
	{
		if (is_min_or_max(tab->head_a, tab->a, 1))
			break ;
		cnt++;
		tab->a = tab->a->next;
	}
	smart_rotate_a(tab, cnt);
}
