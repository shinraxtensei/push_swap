#include"push_swap.h"

int main (int ac, char **av)
{
    t_global    *tab;
    int         *arr;
    int         nbrs_count;

    if(ac == 1)
        return (EXIT_FAILURE);
    nbrs_count = args_manager(ac, av, &arr);
    if (nbrs_count < 0)
        return (EXIT_FAILURE);
    tab = stack_creator();
	if (!initialise_tab(tab, arr, nbrs_count))
	{
		free(arr);
		return (EXIT_FAILURE);
	}
    free(arr);
    sort_handler(tab, nbrs_count);
    free_tab(tab);
    return(EXIT_SUCCESS);
}