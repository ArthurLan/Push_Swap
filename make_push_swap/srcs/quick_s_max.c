/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_s_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:41:06 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 23:47:41 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		in_stk_a(t_stk *stk, int val)
{
	int top;

	top = stk->top_a + 1;
	while (--top)
	{
		if (stk->stk_a[top] == val)
			return (1);
	}
	return (0);
}

static int		val_place(t_stk *stk, int val)
{
	int i;
	int med;

	med = stk->top_b / 2;
	i = 0;
	while (i < stk->top_b && stk->stk_b[i] != val)
		i++;
	if (i > med)
		return (0);
	else
		return (1);
}

static int		select_s_stk(t_stk *stk, int size)
{
	int tmp_stk[size];
	int i;

	i = 0;
	sort_tmp(tmp_stk, stk->stk_b, size, stk->top_b + 1);
	while (size - i > 0)
	{
		if (stk->stk_b[stk->top_b] == tmp_stk[i])
		{
			ft_push(stk, 'b');
			if (in_stk_a(stk, tmp_stk[i]))
				i++;
		}
		else
		{
			if (!(val_place(stk, tmp_stk[i])))
				ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
			else
				ft_rev_rotate(stk, stk->stk_b, stk->top_b, 'b');
		}
	}
	return (0);
}

static void		quick_sa_bis(t_stk *stk, int *size_b, int *size_a, int *b)
{
	if (*size_a <= 3 && sorted(stk) != stk->top_a)
	{
		if (stk->a_empty != 1)
			stk->a_empty = 1;
		*size_a = sort_two_three(stk, *size_a);
	}
	if (stk->top_b && size_b[*b] <= 19 && size_b[*b] > 0)
	{
		if (size_b[*b] <= 3)
			*size_a = push_small_a(stk, &size_b[*b]);
		else
			size_b[*b] = select_s_stk(stk, size_b[*b]);
		if (*b > 1)
			*b -= 1;
	}
	else if (size_b[*b] > 1 && *size_a <= 1)
	{
		*size_a = ft_to_a(stk, size_b[*b], *b);
		size_b[*b] = size_b[*b] - *size_a;
	}
	else if (*b > 1)
	{
		*b -= 1;
		size_b[*b] += 1;
	}
}

void			quick_s_max(t_stk *stk, int s_max)
{
	int size_a;
	int size_b[s_max];
	int b;

	b = 0;
	size_a = s_max;
	size_b[0] = 0;
	size_b[1] = 0;
	while (sorted(stk) < s_max || size_b[1] != 0)
	{
		while (size_a > 3 && sorted(stk) != stk->top_a)
		{
			b++;
			size_b[b] = ft_to_b(stk, size_a);
			size_a = size_a - size_b[b];
		}
		quick_sa_bis(stk, size_b, &size_a, &b);
		if (sorted(stk) >= stk->top_a)
			size_a = 0;
		else
			size_a = stk->top_a - sorted(stk) + 1;
	}
}
