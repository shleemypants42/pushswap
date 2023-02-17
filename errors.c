/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:43:23 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:06:13 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sign(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!check_digit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_letters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_errors(int argc, char **argv)
{
	if (argc == 2)
		checkpoint(argv);
	else if (argc > 2)
	{
		if (check_sign(argv) || check_dup(argv) || check_letters(argv))
		{
			write(1, "ERROR\n", 6);
			exit(0);
		}
	}
}