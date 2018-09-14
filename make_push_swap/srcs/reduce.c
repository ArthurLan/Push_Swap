/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 22:02:28 by alanter           #+#    #+#             */
/*   Updated: 2018/09/13 02:35:41 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*reducepa(char *str)
{
	char		*ret;
	static int	pb = 1;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		while (ft_strncmp(&str[i], "pb\n", 3) != 0 && str[i] != 0)
			ret[j++] = str[i++];
		while (ft_strlen(&str[i]) > 2 && ft_strncmp(&str[i], "pb\n", 3) == 0
				&& (pb += 1))
			i += 3;
		while (ft_strlen(&str[i]) > 2 && ft_strncmp(&str[i], "pa\n", 3) == 0
				&& ((pb -= 1)))
			i += 3;
		while (pb-- > 1)
		{
			ret[j++] = 'p';
			ret[j++] = 'b';
			ret[j++] = '\n';
		}
		pb = 1;
	}
	return (ret);
}

char	*reducepb(char *str)
{
	char		*ret;
	static int	pb = 1;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		while (ft_strncmp(&str[i], "pa\n", 3) != 0 && str[i] != 0)
			ret[j++] = str[i++];
		while (ft_strlen(&str[i]) > 2 && ft_strncmp(&str[i], "pa\n", 3) == 0
				&& (pb += 1))
			i += 3;
		while (ft_strlen(&str[i]) > 2 && ft_strncmp(&str[i], "pb\n", 3) == 0
				&& ((pb -= 1)))
			i += 3;
		while (pb-- > 1)
		{
			ret[j++] = 'p';
			ret[j++] = 'a';
			ret[j++] = '\n';
		}
		pb = 1;
	}
	return (ret);
}

char	*reduce_dbl_r(char *str)
{
	char		*ret;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		if (ft_strncmp(&str[i], "rra\nra\n", 7) == 0)
			i += 7;
		else if (ft_strncmp(&str[i], "\nra\nrra", 7) == 0)
			i += 7;
		else if (ft_strncmp(&str[i], "rrb\nrb\n", 7) == 0)
			i += 7;
		else if (ft_strncmp(&str[i], "\nrb\nrrb", 7) == 0)
			i += 7;
		else if (ft_strncmp(&str[i], "\nsb\nsb", 6) == 0)
			i += 6;
		else if (ft_strncmp(&str[i], "\nsa\nsa", 6) == 0)
			i += 6;
		ret[j++] = str[i++];
	}
	return (ret);
}
