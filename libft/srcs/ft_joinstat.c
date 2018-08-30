/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:17:10 by alanter           #+#    #+#             */
/*   Updated: 2018/08/26 19:20:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Voir ft_utim_join, avec une string statique
*/

static char		*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	char	*d;
	int		i;

	i = 0;
	if (!(d = (char *)ft_memalloc(n1 + n2 + 1)))
		return (NULL);
	while (n1--)
		d[i++] = *s1++;
	while (n2--)
		d[i++] = *s2++;
	return (d);
}

static char		*ft_sort_null(char *s1, char *s2, int n1, int n2)
{
	char *str;

	n1 = (n1 == 0) ? ft_strlen(s1) : n1;
	n2 = (n2 == 0) ? ft_strlen(s2) : n2;
	if ((s1 && s2) || n1 || n2)
		str = ft_strnjoin(s1, s2, n1, n2);
	else if (s1 && s2 == NULL)
		str = ft_strndup(s1, n1);
	else if (s1 == NULL && s2)
		str = ft_strndup(s2, n2);
	else
		str = NULL;
	return (str);
}

char			*ft_joinstat(char **s1, char *s2, int n1, int n2)
{
	char *str;

	str = ft_sort_null(*s1, s2, n1, n2);
	if (*s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (str);
}
