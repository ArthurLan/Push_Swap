/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:50:00 by alanter           #+#    #+#             */
/*   Updated: 2018/08/20 20:53:44 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *stack, int top)
{
	int	tmp;

	if (top > 0)
	{
		tmp = stack[top];
		stack[top] = stack[top - 1];
		stack[top - 1] = tmp;
		ft_printf("swap\n");	
	}
}

void	ft_rotate(int *stack, int top)
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
	}
	ft_printf("rotate\n");	
}

void	ft_rev_rotate(int *stack, int top)
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
	}
	ft_printf("rev_rotate\n");	

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
	ft_printf("push\n");	
}
