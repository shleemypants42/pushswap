/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:21:49 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:16:56 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort4four(t_node **a, t_node **b)
{
	int	min;
	int	position;

	min = min_elem(*a);
	position = elem_pos(*a, min);
	if (position == 1)
		sort4four3(a, b);
	if (position == 2)
	{
		swap_a(a);
		if (is_sorted(*a))
			return ;
		sort4four3(a, b);
	}
	sort4four2(a, b, position);
}

void	sort4four2(t_node **a, t_node **b, int position)
{
	if (position == 3)
	{
		revrotate_a(a);
		revrotate_a(a);
		sort4four3(a, b);
	}
	if (position == 4)
	{
		revrotate_a(a);
		if (is_sorted(*a))
			return ;
		sort4four3(a, b);
	}
}

void	sort4four3(t_node **a, t_node **b)
{
	push_b(a, b);
	sort4three(a);
	push_a(a, b);
}

void	sort4more(t_node **a, t_node **b)
{
	int	i[5];

	i[0] = 0;
	i[1] = list_size(*a);
	i[2] = min_elem(*a);
	i[3] = elem_pos(*a, i[2]);
	while (1)
	{
		i[4] = list_size(*a);
		if (i[4] == 4)
			break ;
		i[2] = min_elem(*a);
		if ((*a)->data == i[2])
		{
			push_b(a, b);
			i[0]++;
		}
		else if (i[3] < i[1] / 2)
			rotate_a(a);
		else
			revrotate_a(a);
	}
	sort4four(a, b);
	sort4more2(a, b, i[0]);
}

void	sort4more2(t_node **a, t_node **b, int n)
{
	while (n)
	{
		push_a(a, b);
		n--;
	}
}