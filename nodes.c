/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:13:26 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/17 08:52:28 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	node_creation(t_node **head, int data)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
	{
		write(1, "ERROR\n", 6);
		return ;
	}
	temp->data = data;
	temp->next = temp;
	temp->prev = temp;
	(*head) = temp;
	free(temp);
}

void	to_the_back(t_node **head, int data)
{
	t_node	*last;
	t_node	*new;

	node_creation(&new, data);
	if (!(*head))
		return ;
	last = (*head)->prev;
	last->next = new;
	new->prev = last;
	new->next = (*head);
	(*head)->prev = new;
}

void	to_the_beginning(t_node **head, int data)
{
	t_node	*new;

	node_creation(&new, data);
	new->data = data;
	new->next = NULL;
	if (!(*head))
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	remove_first(t_node **node)
{
	t_node	*temp;

	if ((*node) == NULL)
		return ;
	temp = (*node);
	*node = (*node)->next;
	free(temp);
}

void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}