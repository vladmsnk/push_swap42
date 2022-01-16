#include "push_swap_lib.h"

static void	swap_elems(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (a[j] > a[j + 1])
				swap_elems(&a[j], &a[j + 1]);
			j++;
		}
		i++;
	}
}