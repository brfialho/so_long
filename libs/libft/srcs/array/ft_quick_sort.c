/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:38:23 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/18 18:10:09 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *array, int start, int end);
static void	swap(int *array, int j, int i);

void	ft_quick_sort(int *array, int start, int end)
{
	int	pivot_index;

	if (end - start < 1)
		return ;
	pivot_index = partition(array, start, end);
	ft_quick_sort(array, start, pivot_index - 1);
	ft_quick_sort(array, pivot_index + 1, end);
}

static int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = start - 1;
	j = start - 1;
	pivot = array[start + (end - start) / 2];
	swap(array, start + (end - start) / 2, end);
	while (++i < end)
		if (array[i] < pivot)
			swap(array, i, ++j);
	swap(array, j + 1, end);
	return (j + 1);
}

static void	swap(int *array, int j, int i)
{
	int	tmp;

	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}
// int main(void)
// {
// 	// int size = 5;
// 	// int array[5] = {30, 10, 40, 80, 90};
// 	int size = 14;
// 	int array[14] = {5, 4, 3, 2, 1, 11, 200, 0 , 5, 5, -10, -128, 1111, 200};
// 	ft_printf("BEFORE:\n");
// 	for (int i = 0; i < size; i++)
// 		ft_printf("%d ", array[i]);
// 	ft_printf("\n");

// 	ft_quick_sort(array, 0, size - 1);

// 	ft_printf("AFTER:\n");
// 	for (int j = 0; j < size; j++)
// 		ft_printf("%d ", array[j]);
// 	ft_printf("\n");
// }

// first implementation just for comparison
// void	ft_quicksort(int *array, int len)
// {
// 	int	i;
// 	int	j;
// 	int	pivot;

// 	if (len <= 1)
// 		return ;
// 	i = -1;
// 	j = 0;
// 	pivot = array[len / 2];
// 	swap(array, len / 2, len - 1);
// 	while (--len)
// 		if (array[j++] < pivot)
// 			swap(array, j - 1, ++i);
// 	swap(array, j, i + 1);
// 	ft_quicksort(array, ++i);
// 	ft_quicksort(array + 1 + i, j - i);
// }