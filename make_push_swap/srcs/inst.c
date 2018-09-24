/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:50:00 by alanter           #+#    #+#             */
/*   Updated: 2018/09/14 16:32:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stk *stk, int *stack, int top, int select)
{
	int	tmp;

	if (top > 0)
	{
		tmp = stack[top];
		stack[top] = stack[top - 1];
		stack[top - 1] = tmp;
		if (select == 'a')
		{
			stk->inst = ft_joinstat(&stk->inst, "sa\n", 0, 0);
			if (stk->top_b > 1 && stk->stk_b[stk->top_b - 1]
					> stk->stk_b[stk->top_b])
				ft_swap(stk, stk->stk_b, stk->top_b, 'b');
		}
		else if (select == 'b')
		{
			stk->inst = ft_joinstat(&stk->inst, "sb\n", 0, 0);
			if (stk->top_a > 1 && stk->stk_a[stk->top_a - 1]
					< stk->stk_a[stk->top_a])
				ft_swap(stk, stk->stk_a, stk->top_a, 'a');
		}
	}
}

void	ft_rotate(t_stk *stk, int *stack, int top, int select)
{
	int	tmp;
	int i;

	if (top > 0)
	{
		i = -1;
		tmp = stack[top];
		while (++i < top)
			stack[top - i] = stack[top - i - 1];
		stack[0] = tmp;
		if (select == 'a')
		{
			stk->inst = ft_joinstat(&stk->inst, "ra\n", 0, 0);
			if (stk->top_b > 0 && stk->stk_b[0] > stk->stk_b[stk->top_b])
				ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
		}
		else if (select == 'b')
			stk->inst = ft_joinstat(&stk->inst, "rb\n", 0, 0);
	}
}

void	ft_rev_rotate(t_stk *stk, int *stack, int top, int select)
{
	int	tmp;
	int i;

	if (top > 0)
	{
		i = -1;
		tmp = stack[0];
		while (++i < top)
			stack[i] = stack[i + 1];
		stack[top] = tmp;
		if (select == 'a')
			stk->inst = ft_joinstat(&stk->inst, "rra\n", 0, 0);
		else if (select == 'b')
			stk->inst = ft_joinstat(&stk->inst, "rrb\n", 0, 0);
	}
}

void	ft_push(t_stk *stk, int select)
{
	if (select == 'a' && stk->top_a >= 0)
	{
		(stk->top_b)++;
		stk->stk_b[stk->top_b] = stk->stk_a[stk->top_a];
		(stk->top_a)--;
		stk->inst = ft_joinstat(&stk->inst, "pb\n", 0, 0);
	}
	else if (select == 'b' && stk->top_b >= 0)
	{
		(stk->top_a)++;
		stk->stk_a[stk->top_a] = stk->stk_b[stk->top_b];
		(stk->top_b)--;
		stk->inst = ft_joinstat(&stk->inst, "pa\n", 0, 0);
	}
}
