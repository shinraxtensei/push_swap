#include"../../push_swap.h"

static int	reverse_rotate(t_list **head, int sz)
{
	if (!*head)
		return (1);
	if (sz < 2)
		return (1);
	(*head)->prev = ft_lstlast(*head);
	(*head)->prev->prev->next = NULL;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	rra(t_global *tab, int print)
{
	if (reverse_rotate(&tab->head_a, tab->a_sz))
		return ;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_global *tab, int print)
{
	if (reverse_rotate(&tab->head_b, tab->b_sz))
		return ;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_global *tab, int print)
{
	int	exec;

	exec = 2;
	if (reverse_rotate(&tab->head_a, tab->a_sz))
		exec--;
	if (reverse_rotate(&tab->head_b, tab->b_sz))
		exec--;
	if (print && exec)
		ft_putstr_fd("rrr\n", 1);
}
