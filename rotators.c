/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:22:20 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 12:16:16 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(t_node **a)
{
	(*a) = (*a)->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **b)
{
	(*b) = (*b)->next;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_node **a, t_node **b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
}

void	revrotate_a(t_node **a)
{
	(*a) = (*a)->prev;
	write(1, "rra\n", 4);
}

void	revrotate_b(t_node **b)
{
	(*b) = (*b)->prev;
	write(1, "rrb\n", 4);
}