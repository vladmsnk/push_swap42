#include "push_swap_lib.h"
#include <stdio.h>

static void	with_zeros(int *minus_cnt, int *plus_cnt, int *iter, long *nmbr)
{
	*minus_cnt = 0;
	*plus_cnt = 0;
	*iter = 0;
	*nmbr = 0;
}

long	ft_atoi(const char *str)
{
	int		minus_cnt;
	int		plus_cnt;
	int		iter;
	long	nmbr;

	with_zeros(&minus_cnt, &plus_cnt, &iter, &nmbr);
	while (str[iter] == ' ' || (str[iter] >= '\t' && str[iter] <= '\r'))
		iter++;
	while (str[iter] == '-' || str[iter] == '+')
	{
		if (str[iter] == '-')
			minus_cnt++;
		else if (str[iter] == '+')
			plus_cnt++;
		iter++;
	}
	if ((minus_cnt >= 1 && plus_cnt >= 1) || (minus_cnt > 1 || plus_cnt > 1))
		return (nmbr);
	while (str[iter] >= '0' && str[iter] <= '9')
		nmbr = nmbr * 10 + (str[iter++] - 48);
	if (minus_cnt == 1)
		return (-1 * nmbr);
	return (nmbr);
}