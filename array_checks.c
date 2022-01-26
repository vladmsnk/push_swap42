#include "push_swap_lib.h"

int	check_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	if (len == 1)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_parts_sorted(int *arr, int point,int len)
{
	int	new_array[len];
	int	i;

	i = 0;
	while (i < len - point - 1)
	{
		new_array[i] = arr[point + 1 + i];
		i++; 
	}
	while (i < len)
	{
		new_array[i] = arr[i - (len - point - 1)];
		i++; 
	}
	return (check_sorted(new_array, len));
}

int	check_elmost_sorted(int *arr, int len)
{
	int	i;
	int	point;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			point = i;
			cnt++;
		}
		i++;
	}
	if (cnt == 1)
		return check_parts_sorted(arr, point, len);
	return (0);
}


// int main() 
// {
// 	int arr[] = {2, 3,4, 5, 6, 7, 1 , 2};
// 	printf("%d\n", check_elmost_sorted(arr, 7));
// }