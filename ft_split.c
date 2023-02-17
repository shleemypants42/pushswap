/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:51:09 by dfurneau          #+#    #+#             */
/*   Updated: 2023/02/16 13:10:42 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_str_len(const char *str, char c, int *index)
{
	int	i;

	i = 0;
	while (str[*index] != c && str[*index])
	{
		i++;
		(*index)++;
	}
	return (i);
}

int	ft_str_nbr(const char *str, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			nbr++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nbr);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s))
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	sub = malloc(sizeof(char) * len + 1);
	if (!(sub))
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	**ft_split(const char *s, char c)
{
	char	**str;
	int		index;
	int		len;
	int		i;
	int		start;

	index = 0;
	str = (char **)malloc(sizeof(char *) * ft_str_nbr(s, c) + 1);
	if (!(str))
		return (0);
	while (s[index] && s[index] == c)
		index++;
	i = 0;
	while (s[index])
	{
		start = index;
		if (s[index] != c && i < ft_str_nbr(s, c))
		{
			len = ft_str_len(s, c, &index);
			str[i++] = ft_substr(s, start, len);
		}
		index++;
	}
	str[i] = 0;
	return (str);
}