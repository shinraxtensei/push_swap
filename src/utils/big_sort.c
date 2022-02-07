#include"../push_swap.h"
#include<stdio.h>

// void	smart_rotate_b_test(t_global *tab, int n)
// {
// 	if (n > tab->b_sz / 2)
// 	{
// 		n = tab->b_sz - n;
// 		while (n--)
// 			rrb(tab, 1);
// 	}
// 	else
// 		while (n--)
// 			rb(tab, 1);
// }

static void	push_in_chunks(t_global *tab, int chunk_sz)
{
	int	chunk_n;
	int	cnt;

	chunk_n = 1;
	cnt = 0;
	while (tab->a_sz)
	{
		if (*(int *)tab->head_a->data < (chunk_sz * chunk_n))
		{
			pb(tab, 1);
			if (*(int *)tab->head_b->data < chunk_sz * chunk_n - (chunk_sz / 2))
				rb(tab, 1);
			cnt++;
		}
		else
			ra(tab, 1);
		if (cnt == chunk_sz * chunk_n)
			chunk_n++;
	}
}

static void	push_back_in_order(t_global *tab)
{
	while (tab->b_sz)
	{
		if (smart_rotate_b(tab))
		{
			pa(tab, 1);
			if (tab->b_sz > 1
				&& *(int *)tab->head_b->data < *(int *)tab->head_b->next->data)
				ss(tab, 1);
			else
				sa(tab, 1);
		}
		else
			pa(tab, 1);
	}
}


// static void	push_back_in_order(t_global *tab)
// {
// 	int count = 1;
// 	tab->b = tab->head_b;
// 	while (tab->b_sz)
// 	{
// 		if(is_min_or_max(tab->b , tab->head_b ,0))
// 		{
// 			smart_rotate_b_test(tab, count);
// 			pa(tab, 1);

// 		}
// 		else
// 			pa(tab, 1);
// 		count++;
// 		tab->head_b = tab->head_b->next;
// 	}
	
// }


void	big_sort(t_global *tab)
{
	int	chunk_sz;

	chunk_sz = tab->a_sz / 12 + 22;
	push_in_chunks(tab, chunk_sz);
	push_back_in_order(tab);
}