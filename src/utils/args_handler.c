/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:41:10 by ahouari           #+#    #+#             */
/*   Updated: 2022/02/16 08:41:16 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static int	*create_int_arr(int n_cnt, char **nbrs)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * n_cnt);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < n_cnt)
		arr[i] = ft_atoi(nbrs[i]);
	return (arr);
}

static int	check_doubles(int *arr, int n_cnt)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n_cnt)
	{
		j = i;
		while (++j < n_cnt)
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

static int	args_checker(int n_cnt, char **nbrs, int **arr)
{
	if (n_cnt < 1 || check_args(nbrs))
		return (1);
	*arr = create_int_arr(n_cnt, nbrs);
	if (!*arr)
		return (1);
	if (check_doubles(*arr, n_cnt))
	{
		free(*arr);
		return (1);
	}
	return (0);
}

static char	**pimp_my_args(int ac, char **av)
{
	char	**nbrs;
	char	*av_str;
	char	*tmp;
	int		i;

	av_str = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		tmp = ft_strjoin(av_str, av[i]);
		free(av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free(av_str);
		av_str = tmp;
	}
	nbrs = ft_split(av_str, ' ');
	free(av_str);
	return (nbrs);
}

int	args_manager(int ac, char **av, int **arr)
{
	char	**nbrs;
	int		i;
	int		nbrs_count;

	nbrs_count = 0;
	i = -1;
	nbrs = pimp_my_args(ac, av);
	while (nbrs[++i])
		nbrs_count++;
	if (args_checker(nbrs_count, nbrs, arr))
		nbrs_count = -1;
	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
	if (nbrs_count < 0)
		ft_putstr_fd("Error\n", 2);
	return (nbrs_count);
}
