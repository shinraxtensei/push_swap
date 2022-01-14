#include"../push_swap.h"
#include<stdio.h>
t_global	*stack_creator(void)
{
	t_global	*tab;

	tab = (t_global *)ft_calloc(sizeof(t_global), 1);
	if (!tab)
		return (NULL);
	tab->head_a = NULL;
	tab->head_b = NULL;
	return (tab);
}

void	free_tab(t_global *tab)
{
	if (!tab)
		return ;
	if (tab->head_a)
		ft_lstclear(&tab->head_a, free);
	if (tab->head_b)
		ft_lstclear(&tab->head_b, free);
	free(tab);
}

int	initialise_tab(t_global *tab, int *arr, int n_cnt)
{
	int	cnt;
	int	i;
	int	j;
	int	*tmp;

	i = -1;
	while (++i < n_cnt)
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return (0);
		cnt = 0;
		j = -1;
		while (++j < n_cnt)
			if (j != i && arr[j] < arr[i])
				cnt++;
		*tmp = cnt;
		ft_lstadd_back(&tab->head_a, ft_lstnew(tmp));
		tmp = NULL;
	}
	tab->a_sz = ft_lstsize(tab->head_a);
	return (1);
}