/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:42:07 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/11 08:53:40 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../push_swap.h"

static int	shift(t_list **head, int sz)
{
	if (!*head)
		return (1);
	if (sz < 2)
		return (1);
	*head = (*head)->next;
	(*head)->prev->prev = ft_lstlast(*head);
	(*head)->prev->next = NULL;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	ra(t_global *tab, int print)
{
	if (shift(&tab->head_a, tab->a_sz))
		return ;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_global *tab, int print)
{
	if (shift(&tab->head_b, tab->b_sz))
		return ;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_global *tab, int print)
{
	int	exec;

	exec = 2;
	if (shift(&tab->head_a, tab->a_sz))
		exec--;
	if (shift(&tab->head_b, tab->b_sz))
		exec--;
	if (print && exec)
		ft_putstr_fd("rr\n", 1);
}
