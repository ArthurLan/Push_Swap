/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:50:00 by alanter           #+#    #+#             */
/*   Updated: 2018/08/31 01:08:40 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// INCLURE LES JOINSTAT ICI !!!

void	ft_swap(t_stk *stk, int *stack, int top, int select)
{
	int	tmp;

	if (top > 0)
	{
		tmp = stack[top];
		stack[top] = stack[top - 1];
		stack[top - 1] = tmp;
		if (select == 'a')
			stk->inst = ft_joinstat(&stk->inst, "sa\n", 0, 0);
		else if (select == 'b')
			stk->inst = ft_joinstat(&stk->inst, "sb\n", 0, 0);
		//ft_printf("swap\n");	
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
			stk->inst = ft_joinstat(&stk->inst, "ra\n", 0, 0);
		else if (select == 'b')
			stk->inst = ft_joinstat(&stk->inst, "rb\n", 0, 0);
	}
	//ft_printf("rotate\n");	
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
	//ft_printf("rev_rotate\n");	

}

void	ft_push(int *src, int *dst, int *top_s, int *top_d)
{
	//ft_printf("1 my *top_d is : %d\n", *top_d);
	if (*top_s >= 0)
	{
		(*top_d)++;
		dst[*top_d] = src[*top_s];
		(*top_s)--;
	}
	//ft_printf("push\n");	
}
