/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:53:56 by alanter           #+#    #+#             */
/*   Updated: 2018/08/29 16:46:35 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    write_stack(t_stk stk, int argc);

void	selection_s(t_stk *stk, int size)
{
	int i;

	i = 0;
	while (size)
	{
		while (stk->stk_a[i] != stk->stk_s[size])
			i++;
		if (i >= size / 2)
		{
			while (stk->stk_a[stk->top_a] != stk->stk_s[size])
			{
				ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
			}
		}
		else
		{
			while (stk->stk_a[stk->top_a] != stk->stk_s[size])
			{
				ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
			}
		}
		ft_push(stk->stk_a, stk->stk_b, &stk->top_a, &stk->top_b);
		stk->inst = ft_joinstat(&stk->inst, "pb\n", 0, 0);
		size--;
		i = 0;
	}
	while (stk->top_b + 1)
	{
		stk->inst = ft_joinstat(&stk->inst, "pa\n", 0, 0);
		ft_push(stk->stk_b, stk->stk_a, &stk->top_b, &stk->top_a);
	}
}
