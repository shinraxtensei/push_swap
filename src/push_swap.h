
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include"../libft/libft.h"
#include"../gnl/get_next_line.h"

typedef struct s_global
{
	t_list	*a;
	t_list	*b;
	t_list	*head_a;
	t_list	*head_b;
	int		a_sz;
	int		b_sz;
}	t_global;

// args handler
int args_manager(int ac, char **av, int **arr);
int	check_args(char **nbrs);

// stack handler
t_global	*stack_creator(void);
void	free_tab(t_global *tab);
int	initialise_tab(t_global *tab, int *arr, int n_cnt);

// sort handler

void    sort_handler(t_global *tab, int nbrs_count);
void    small_sort(t_global *tab, int nbrs_count);

// small sort utils
void	smart_push(t_global *tab);
void	sort_a(t_global *tab);
int	is_min_or_max(t_list *head, t_list *element, int find_min);


// big sort
void	big_sort(t_global *tab);
int	smart_rotate_b(t_global *tab);
void	smart_rotate_b_test(t_global *tab, int n);

// action
void    pa(t_global *tab, int print);
void    pb(t_global *tab, int print);
void	sa(t_global *tab, int print);
void	sb(t_global *tab, int print);
void	ss(t_global *tab, int print);
void	ra(t_global *tab, int print);
void	rb(t_global *tab, int print);
void	rr(t_global *tab, int print);
void	rra(t_global *tab, int print);
void	rrb(t_global *tab, int print);
void	rrr(t_global *tab, int print);



# endif
