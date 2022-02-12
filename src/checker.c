/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:30:36 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/10 18:31:27 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	err_exit(t_global *tab)
{
	ft_putstr_fd("Error\n", 1);
	free_tab(tab);
	exit(EXIT_SUCCESS);
}

static int	is_sorted(t_global *tab, int n_cnt)
{
	if (tab->b_sz || tab->a_sz != n_cnt)
		return (0);
	tab->a = tab->head_a;
	while (tab->a->next)
	{
		if (*(int *)tab->a->data > *(int *)tab->a->next->data)
			return (0);
		tab->a = tab->a->next;
	}
	return (1);
}

static void	eval_line(t_global *tab, char *line)
{
	if (ft_strnstr(line, "sa\n", 3))
		sa(tab, 0);
	else if (ft_strnstr(line, "sb\n", 3))
		sb(tab, 0);
	else if (ft_strnstr(line, "ss\n", 3))
		ss(tab, 0);
	else if (ft_strnstr(line, "pa\n", 3))
		pa(tab, 0);
	else if (ft_strnstr(line, "pb\n", 3))
		pb(tab, 0);
	else if (ft_strnstr(line, "ra\n", 3))
		ra(tab, 0);
	else if (ft_strnstr(line, "rb\n", 3))
		rb(tab, 0);
	else if (ft_strnstr(line, "rr\n", 3))
		rr(tab, 0);
	else if (ft_strnstr(line, "rra\n", 4))
		rra(tab, 0);
	else if (ft_strnstr(line, "rrb\n", 4))
		rrb(tab, 0);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr(tab, 0);
	else
		err_exit(tab);
}

static void	handle_check(t_global *tab, int n_cnt)
{
	char	*line;

	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		eval_line(tab, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(tab, n_cnt))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int			*arr;
	int			n_cnt;

	if (ac == 1)
		return (EXIT_SUCCESS);
	n_cnt = args_manager(ac, av, &arr);
	if (n_cnt < 0)
		return (EXIT_FAILURE);
	tab = stack_creator();
	if (!initialise_tab(tab, arr, n_cnt))
	{
		free(arr);
		return (EXIT_FAILURE);
	}
	free(arr);
	handle_check(tab, n_cnt);
	free_tab(tab);
	return (EXIT_SUCCESS);
}
