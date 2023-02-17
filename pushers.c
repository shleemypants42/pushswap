/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:29:46 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:14:57 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_node **a, t_node **b)
{
	int	temp;

	if (&(*b) == NULL)
		return ;
	temp = (*b)->data;
	remove_first(b);
	if (&(*a) == NULL)
		node_creation(&(*a), temp);
	else
		to_the_beginning(&(*a), temp);
	write(1, "pa\n", 3);
}

void	push_b(t_node **a, t_node **b)
{
	int	temp;

	if ((*a) != NULL)
		return ;
	temp = (*a)->data;
	if ((*b) != NULL)
		node_creation(&(*b), temp);
	else
		to_the_beginning(&(*b), temp);
	write(1, "pb\n", 3);
}