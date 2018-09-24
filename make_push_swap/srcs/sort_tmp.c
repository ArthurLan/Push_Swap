/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 02:31:51 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 02:51:50 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tmp(int *tmp_stk, int *src_stk, int size, int top)
{
	int i;

	i = 0;
	while (++i <= size)
		tmp_stk[size - i] = src_stk[top - i];
	quicksort(&tmp_stk, 0, size);
}

int		sorted(t_stk *stk)
{
	int nb_sort;

	nb_sort = 0;
	while (nb_sort <= stk->top_a && stk->stk_a[nb_sort] == stk->stk_s[nb_sort])
		nb_sort++;
	return (nb_sort);
}
