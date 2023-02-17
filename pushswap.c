/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:30:06 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/17 08:32:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_chunkz(t_node **a, t_node **b, t_node **temp)
{
	int	size;

	size = list_size(*a);
	init_alias(a, temp);
	if (size <= 34)
		small_chunkz_sort(temp, b, size);
	if (size > 35 && size <= 134)
		medium_chunkz(temp, b);
	if (size > 135 && size <= 500)
		big_chungus(temp, b);
	if (size >= 501)
		big_chungus(temp, b);
}

void	sorting_data(t_node **a, t_node **b, t_node **temp)
{
	if (is_sorted(*a) == 1)
	{
		free_list((*a));
		return ;
	}
	sorting_chunkz(a, b, temp);
	free_list(*a);
	free_list(*temp);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*temp;

	a = NULL;
	b = NULL;
	temp = NULL;
	check_errors(argc, argv);
	if (argc >= 2)
	{
		if (argc == 2)
			init_str(&a, argv[1]);
		else
			init_args(&a, argv);
		sorting_data(&a, &b, &temp);
	}
	return (0);
}
