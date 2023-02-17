/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:39:09 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/17 07:22:39 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_str(t_node **a, char *str)
{
	int		i;
	int		j;
	char	**split;
	int		nbrs;

	i = 0;
	j = 1;
	split = ft_split(str, ' ');
	nbrs = ft_atoil(split, split[0]);
	node_creation(a, nbrs);
	while (split[j])
	{
		to_the_back(a, ft_atoil(split, split[j]));
		j++;
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	init_args(t_node **a, char **argv)
{
	int	i;

	i = 2;
	node_creation(&(*a), ft_atoi(argv[1]));
	while (argv[i])
	{
		to_the_back(&(*a), ft_atoi(argv[i]));
		i++;
	}
}

void	custom_alias(t_node **alias, int data)
{
	if (!(*alias))
		node_creation(alias, data);
	else
		to_the_back(alias, data);
}

void	init_alias(t_node **node, t_node **alias)
{
	int		i[5];
	t_node	*temp;
	t_node	*temp2;

	i[0] = 0;
	i[4] = list_size(*node);
	temp = (*node);
	while (i[0] < i[4])
	{
		i[3] = temp->data;
		i[0] = 0;
		i[2] = 0;
		temp2 = (*node);
		while (i[1] < i[4])
		{
			if (i[3] > temp2->next->data)
				i[2]++;
			temp2 = temp2->next;
			i[1]++;
		}
		temp2 = temp2->next;
		custom_alias(alias, i[2]);
		temp = temp->next;
		i[0]++;
	}
}
