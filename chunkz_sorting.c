/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkz_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:56:25 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:00:25 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	small_chunkz_sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort4two(a);
	if (size == 3)
		sort4three(a);
	if (size == 4)
		sort4four(a, b);
	if (size >= 5 && size <= 34)
		sort4more(a, b);
}

void	a_to_b(t_node **a, t_node **b, int min, int max)
{
	int	size;

	while (1)
	{
		if ((*a)->data >= min && (*a)->data <= max)
		{
			push_b(a, b);
			if ((*b)->data <= (max + min) / 2)
				rotate_b(b);
		}
		else
			rotate_a(a);
		if (*b)
		{
			size = list_size(*b);
			if (size == max + 1)
				break ;
		}
	}
}

void	sort_chunkz(t_node **a, t_node **b)
{
	int	max;
	int	position;
	int	size;

	while (1)
	{
		max = max_elem(*b);
		position = elem_pos(*b, max);
		size = list_size(*b);
		if ((*b)->data == max)
			push_a(a, b);
		else if (position <= (size / 2))
			rotate_b(b);
		else
			revrotate_b(b);
		if (size == 2)
			break ;
	}
	if ((*b)->data < (*b)->next->data)
		swap_b(b);
	push_a(a, b);
	push_a(a, b);
}

void	medium_chunkz(t_node **a, t_node **b)
{
	int	min;
	int	max;
	int	size;
	int i;
	int	temp;

	i = 0;
	size = list_size(*a);
	min = size / 4;
	min--;
	max = min;
	while (max < size)
	{
		a_to_b(a, b, i, max);
		i = max + 1;
		temp = max;
		max += min;
	}
	if (size - temp == 4)
		sort4three(a);
	else
		sort4more(a, b);
	sort_chunkz(a, b);
}

void	big_chungus(t_node **a, t_node **b)
{
	int	size;
	int	min;
	int	max;
	int	i;

	size = list_size(*a);
	i = 0;
	min = size / 9;
	min--;
	max = min;
	while (max < size - 11)
	{
		a_to_b(a, b, i - 1, max + 4);
		i = max + 2;
		max += min;
	}
	sort4more(a, b);
	sort_chunkz(a, b);
}