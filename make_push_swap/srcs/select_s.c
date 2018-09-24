/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:55:09 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 05:33:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_three(t_stk *stk, int size)
{
	if (size == 2)
	{
		if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 1])
			ft_swap(stk, stk->stk_a, stk->top_a, 'a');
	}
	if (size == 3)
	{
		if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 1]
				&& stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 2])
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
		if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 1])
			ft_swap(stk, stk->stk_a, stk->top_a, 'a');
		if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 2])
			ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
		if (stk->stk_a[stk->top_a - 1] > stk->stk_a[stk->top_a - 2])
		{
			ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_swap(stk, stk->stk_a, stk->top_a, 'a');
		}
	}
}

void	select_s_real(t_stk *stk, int size)
{
	int i;

	i = 0;
	while (--size)
	{
		while (stk->stk_a[i] != stk->stk_s[size])
			i++;
		if (i >= size / 2)
		{
			while (stk->stk_a[stk->top_a] != stk->stk_s[size])
				ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
		}
		else
		{
			while (stk->stk_a[stk->top_a] != stk->stk_s[size])
				ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
		}
		ft_push(stk, 'a');
		i = 0;
	}
	while (stk->top_b + 1)
		ft_push(stk, 'b');
}

void	select_s(t_stk *stk, int size)
{
	if (size <= 3)
		sort_less_three(stk, size);
	else
		select_s_real(stk, size);
}
