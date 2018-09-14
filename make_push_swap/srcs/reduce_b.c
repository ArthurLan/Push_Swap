/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:34:09 by alanter           #+#    #+#             */
/*   Updated: 2018/09/13 02:35:39 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*reducerr(char *str)
{
	char		*ret;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		while (ft_strncmp(&str[i], "\nra", 3) != 0
				&& ft_strncmp(&str[i], "\nrb", 3) != 0 && str[i] != 0)
			ret[j++] = str[i++];
		if (ft_strlen(&str[i]) > 6 && (ft_strncmp(&str[i], "\nra\nrb", 6) == 0
					|| ft_strncmp(&str[i], "\nrb\nra", 6) == 0))
		{
			ret[j++] = '\n';
			ret[j++] = 'r';
			ret[j++] = 'r';
			i += 6;
		}
		else if (str[i] != 0)
			ret[j++] = str[i++];
	}
	return (ret);
}

char	*reducerrr(char *str)
{
	char		*ret;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		while (ft_strncmp(&str[i], "\nrra", 3) != 0 && str[i] != 0)
			ret[j++] = str[i++];
		if (ft_strlen(&str[i]) > 8 && ft_strncmp(&str[i], "\nrra\nrrb", 8) == 0)
		{
			ret[j++] = '\n';
			ret[j++] = 'r';
			ret[j++] = 'r';
			ret[j++] = 'r';
			i += 8;
		}
		else if (str[i] != 0)
			ret[j++] = str[i++];
	}
	return (ret);
}

char	*reducess(char *str)
{
	char		*ret;
	static int	i = 0;
	static int	j = 0;

	ret = (char *)ft_memalloc(ft_strlen(str) + 1);
	while (str != NULL && str[i] != 0)
	{
		while (ft_strncmp(&str[i], "\nsa", 3) != 0
				&& ft_strncmp(&str[i], "\nsb", 3) != 0 && str[i] != 0)
			ret[j++] = str[i++];
		if (ft_strlen(&str[i]) > 6 && (ft_strncmp(&str[i], "\nsa\nsb", 6) == 0
					|| ft_strncmp(&str[i], "\nsb\nsa", 6) == 0))
		{
			ret[j++] = '\n';
			ret[j++] = 's';
			ret[j++] = 's';
			i += 6;
		}
		else if (str[i] != 0)
			ret[j++] = str[i++];
	}
	return (ret);
}
