/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:42:07 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/17 09:14:27 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	while (i < list_size(head))
	{
		if (current->data > current->next->data)
			break ;
		current = current->next;
		i++;
	}
	if (i + 1 < list_size(head))
		return (0);
	else
		return (1);
	return (0);
}

int	list_size(t_node *head)
{
	int		i;
	int		data;

	i = 1;
	data = head->data;
	head = head->next;
	while (data != head->data)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	min_elem(t_node *node)
{
	t_node	*temp;
	int		min;

	temp = node;
	if (!temp)
		return (-1);
	min = temp->data;
	while (temp)
	{
		if (temp->data > node->data)
			min = node->data;
		temp = temp->next;
	}
	return (min);
}

int	max_elem(t_node *node)
{
	t_node	*temp;
	int		max;

	temp = node;
	if (!temp)
		return (-1);
	max = temp->data;
	while (temp)
	{
		if (temp->data < node->data)
			max = node->data;
		temp = temp->next;
	}
	return (max);
}

int	elem_pos(t_node *node, int elem)
{
	t_node	*temp;
	int		position;

	position = 1;
	temp = node;
	while (temp != NULL)
	{
		if (temp->data == elem)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}