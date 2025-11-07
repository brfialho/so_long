/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dual_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:07:50 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_pivot
{
	int	first;
	int	second;
}	t_pivot;

static void	partition(int *array, int start, int end, t_pivot *pivots);
static void	swap(int *array, int j, int i);

void	ft_dual_quick_sort(int *array, int start, int end)
{
	t_pivot	pivots;

	if (end - start < 1)
		return ;
	partition(array, start, end, &pivots);
	ft_dual_quick_sort(array, start, pivots.first - 1);
	ft_dual_quick_sort(array, pivots.first + 1, pivots.second - 1);
	ft_dual_quick_sort(array, pivots.second + 1, end);
}

static void	swap(int *array, int j, int i)
{
	int	tmp;

	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}

static void	partition(int *array, int start, int end, t_pivot *pivots)
{
	int	i;
	int	j;
	int	k;

	if (array[start] > array[end])
		swap(array, start, end);
	pivots->first = array[start];
	pivots->second = array[end];
	i = start + 1;
	j = start + 1;
	k = end - 1;
	while (i <= k)
	{
		if (array[i] < pivots->first)
			swap(array, i++, j++);
		else if (array[i] > pivots->second)
			swap(array, i, k--);
		else
			i++;
	}
	swap(array, --j, start);
	swap(array, ++k, end);
	pivots->first = j;
	pivots->second = k;
}

// int main(void)
// {
// 	// int size = 5;
// 	// int array[5] = {30, 10, 40, 80, 90};
// 	int size = 14;
// 	int array[14] = {5, 4, 3, 2, 1, 11, 200, 0 , 5, 5, -10, -128, 1111, 2000};
// 	// int size = 7;
// 	// int array[7] = {30, 10, 20, 80, 90, 50, 70};
// 	ft_printf("BEFORE:\n");
// 	for (int i = 0; i < size; i++)
// 		ft_printf("%d ", array[i]);
// 	ft_printf("\n");

// 	ft_dual_quick_sort(array, 0, size - 1);

// 	ft_printf("AFTER:\n");
// 	for (int j = 0; j < size; j++)
// 		ft_printf("%d ", array[j]);
// 	ft_printf("\n");
// }