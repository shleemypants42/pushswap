/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:57 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:17:20 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_node **a)
{
	int	temp;

	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_node **b)
{
	int	temp;

	temp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = temp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_node **a, t_node **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}