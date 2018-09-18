/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:59:21 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 23:44:25 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_to_b(t_stk *stk, int size)
{
	int med;
	int tmp_stk[size];
	int pushed;
	int rotate;

	sort_tmp(tmp_stk, stk->stk_a, size, stk->top_a + 1);
	med = (size % 2 == 0) ? size / 2 - 1 : size / 2;
	pushed = 0;
	rotate = 0;
	while (pushed <= med || (med == 0 && pushed == 0))
	{
		if (stk->stk_a[stk->top_a] > tmp_stk[med] && (rotate += 1))
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
		else
		{
			ft_push(stk, 'a');
			size--;
			pushed++;
		}
	}
	while (stk->a_empty == 1 && rotate--)
		ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
	return (pushed);
}

int		ft_to_a(t_stk *stk, int size_b, int b)
{
	int med;
	int tmp_stk[size_b];
	int pushed;
	int rotate;

	sort_tmp(tmp_stk, stk->stk_b, size_b, stk->top_b + 1);
	med = (size_b % 2 == 0) ? size_b / 2 - 1 : size_b / 2;
	pushed = 0;
	rotate = 0;
	while (pushed <= med || (med == 0 && pushed == 0))
	{
		if (stk->stk_b[stk->top_b] < tmp_stk[med] && (rotate += 1))
			ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
		else
		{
			ft_push(stk, 'b');
			(size_b)--;
			pushed++;
		}
	}
	while (b > 1 && rotate-- > 0)
		ft_rev_rotate(stk, stk->stk_b, stk->top_b, 'b');
	return (pushed);
}

void	sort_three_b(t_stk *stk, int *size_b, int *pushed)
{
	ft_push(stk, 'b');
	if (stk->stk_b[stk->top_b] < stk->stk_b[stk->top_b - 1])
	{
		ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
		ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
		ft_push(stk, 'b');
		ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
		ft_rev_rotate(stk, stk->stk_b, stk->top_b, 'b');
	}
	else
	{
		ft_push(stk, 'b');
		ft_swap(stk, stk->stk_a, stk->top_a, 'a');
	}
	ft_push(stk, 'b');
	ft_swap(stk, stk->stk_a, stk->top_a, 'a');
	*size_b -= 3;
	*pushed += 3;
}

int		push_small_a(t_stk *stk, int *size_b)
{
	int pushed;

	pushed = 0;
	if (*size_b > 2 && stk->stk_b[stk->top_b] < stk->stk_b[stk->top_b - 2]
			&& stk->stk_b[stk->top_b] < stk->stk_b[stk->top_b - 1])
		sort_three_b(stk, size_b, &pushed);
	while (*size_b)
	{
		ft_push(stk, 'b');
		pushed++;
		*size_b -= 1;
	}
	return (pushed);
}

int		sort_two_three(t_stk *stk, int size)
{
	if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 1])
		ft_swap(stk, stk->stk_a, stk->top_a, 'a');
	if (size > 2)
	{
		if (stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 2])
		{
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_push(stk, 'a');
			ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_push(stk, 'b');
		}
		if (stk->stk_a[stk->top_a - 1] > stk->stk_a[stk->top_a - 2])
		{
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
			ft_swap(stk, stk->stk_a, stk->top_a, 'a');
			ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
		}
	}
	return (0);
}
