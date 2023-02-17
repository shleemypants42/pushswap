/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:37:21 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/15 14:20:37 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort4two(t_node **a)
{
	if ((*a)->data < (*a)->next->data)
		swap_a(a);
}

void	sort4three(t_node **a)
{
	if ((*a)->data < (*a)->next->data)
	{
		if ((*a)->next->data > (*a)->prev->data
			&& (*a)->data < (*a)->prev->data)
		{
			swap_a(a);
			rotate_a(a);
		}
		if ((*a)->data > (*a)->prev->data
			&& (*a)->next->data > (*a)->prev->data)
			revrotate_a(a);
	}
	sort4threept2(a);
}

void	sort4threept2(t_node **a)
{
	if ((*a)->next->data < (*a)->data)
	{
		if ((*a)->data < (*a)->prev->data
			&& (*a)->next->data < (*a)->prev->data)
			swap_a(a);
		if ((*a)->data > (*a)->prev->data
			&& (*a)->next->data > (*a)->prev->data)
		{
			swap_a(a);
			revrotate_a(a);
		}
		if ((*a)->data > (*a)->prev->data
			&& (*a)->next->data < (*a)->prev->data)
			rotate_a(a);
	}
}