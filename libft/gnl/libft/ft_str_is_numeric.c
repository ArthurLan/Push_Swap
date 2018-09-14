/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:47:31 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 16:51:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) == 1 && str != 0)
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}