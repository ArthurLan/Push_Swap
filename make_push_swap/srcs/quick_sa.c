/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:52:05 by alanter           #+#    #+#             */
/*   Updated: 2018/08/31 01:26:10 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void put_tmp_stk(int *tmp_stk, int size);
void    write_stack(t_stk stk, int argc);

int		sorted(t_stk *stk)
{
	int nb_sort;

	nb_sort = 0;
	while (stk->stk_a[nb_sort] == stk->stk_s[nb_sort])
		nb_sort++;
	return (nb_sort);
}

void	sort_tmp(int *tmp_stk, int *src_stk, int size, int top)
{
	int i;

	i = -1;
	while (++i <= size)
		tmp_stk[size - i] = src_stk[top - i];
	quicksort(&tmp_stk, 0, size);
}

int	ft_to_b(t_stk *stk, int size)
{
	int med;
	int tmp_stk[size];
	int pushed;
	int rotate;
	int even_odd;
	
	sort_tmp(tmp_stk, stk->stk_a, size, stk->top_a + 1);
	med = size / 2;
	pushed = 0;
	rotate = 0;
	even_odd = (size % 2 == 0) ? 0 : 1;
	while (pushed < med + even_odd)
	{
		if (stk->stk_a[stk->top_a] > tmp_stk[med])
		{
			rotate++;
			ft_rotate(stk, stk->stk_a, stk->top_a, 'a');
		}
		else
		{
			ft_push(stk->stk_a, stk->stk_b, &stk->top_a, &stk->top_b);
			stk->inst = ft_joinstat(&stk->inst, "pb\n", 0, 0);
			size--;
			pushed++;
		}	
	}
	while (rotate--)
		ft_rev_rotate(stk, stk->stk_a, stk->top_a, 'a');
	return (pushed);
}

int	ft_to_a(t_stk *stk, int size_b)
{
	int med;
	int tmp_stk[size_b];
	int pushed;
	int rotate;
	
	sort_tmp(tmp_stk, stk->stk_b, size_b, stk->top_b + 1);
	med = (size_b % 2 == 0) ? size_b / 2 - 1 : size_b / 2;
	pushed = 0;
	rotate = 0;
	while (pushed <= med || (med == 0 && pushed == 0))// + even_odd)
	{
		if (stk->stk_b[stk->top_b] < tmp_stk[med])
		{
			rotate++;
			ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
		}
		else
		{
			ft_push(stk->stk_b, stk->stk_a, &stk->top_b, &stk->top_a);
			stk->inst = ft_joinstat(&stk->inst, "pa\n", 0, 0);
			(size_b)--;
			pushed++;
		}	
	}
	while (rotate-- > 0)
		ft_rev_rotate(stk, stk->stk_b, stk->top_b, 'b');
	return (pushed);
}

int		push_small_a(t_stk *stk, int *size_b)
{
	int pushed;

	pushed = 0;
	while (*size_b)
	{
		ft_push(stk->stk_b, stk->stk_a, &stk->top_b, &stk->top_a);
		stk->inst = ft_joinstat(&stk->inst, "pa\n", 0, 0);
		pushed++;
		*size_b -= 1;
	}
	return (pushed);
}
		
void	quick_sa(t_stk *stk, int s_max)
{
	int size_a[s_max]; 
	int size_b[s_max]; 
	int a;
	int b;

	size_b[1] = 20;
	a = 0;
	b = -1;
	size_a[a] = s_max;
	size_b[b] = 1;
	int stop = 0;
	while (sorted(stk) != s_max || size_b[0] != 0)
	{
		while (size_a[a] > 1 && sorted(stk) != stk->top_a)
		{
			b++;
			size_b[b] = ft_to_b(stk, size_a[a]);
			size_a[a] = size_a[a] - size_b[b];
		}
		
		if (size_b[b] == 1 && stk->stk_s[stk->top_a + 1] == stk->stk_b[stk->top_b])
		{
			size_a[a] = push_small_a(stk, &size_b[b]);	
			if (b > 0)
				b--;
		}
		else if (size_b[b] > 1 && size_a[a] <= 1)
		{
			size_a[a] = ft_to_a(stk, size_b[b]);	
			size_b[b] = size_b[b] - size_a[a];
		}
		else if (b > 0)
		{
			b--;
			size_b[b] += 1;
		}
		if (stk->top_a > 0 && stk->stk_a[stk->top_a] > stk->stk_a[stk->top_a - 1])
			ft_swap(stk, stk->stk_a, stk->top_a, 'a');
		if (sorted(stk) == stk->top_a)
			size_a[a] = 0;
		else
			size_a[a] = stk->top_a - sorted(stk) + 1;
	}
	stk->top_a = s_max - 1;
	stk->top_b = -1;
}





void put_tmp_stk(int *tmp_stk, int size)
{
	int i;

	i = -1;
	while (++i <= size)
	{
		ft_printf("Voilà mon tmp_stk[%d] : %d\n", size - i, tmp_stk[size - i]);
	}
}
