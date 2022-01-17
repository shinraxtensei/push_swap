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
	int		i;

	av_str = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		av_str = ft_strjoin(av_str, av[i]);
		av_str = ft_strjoin(av_str, " ");
	}
	nbrs = ft_split(av_str, ' ');
	free(av_str);
	return (nbrs);
}

int args_manager(int ac, char **av, int **arr)
{
    char    **nbrs;
    int     i;
    int     nbrs_count;

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
    if(nbrs_count < 0)
        ft_putstr_fd("Error , radi ykoun rir chi blan fl args\n", 2);
    return (nbrs_count);
}