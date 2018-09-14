/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:52:05 by alanter           #+#    #+#             */
/*   Updated: 2018/09/14 16:47:00 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_stack(t_stk stk, int argc)
{
	int i;

	i = -1;
	while (++i <=  stk.top_a)
	{
		ft_printf("Voilà mon stack_a[%d] : %d\n", stk.top_a - i, stk.stk_a[stk.top_a - i]);
	}
	ft_putendl("");
	i = -1;
	while (++i <= stk.top_b)
	{
		ft_printf("Voilà mon stack_b[%d] : %d\n", stk.top_b - i, stk.stk_b[stk.top_b - i]);
	}
	ft_putendl("######################");
	i = -1;
}

int		sorted(t_stk *stk)
{
	int nb_sort;

	nb_sort = 0;
	while (nb_sort <= stk->top_a && stk->stk_a[nb_sort] == stk->stk_s[nb_sort])
		nb_sort++;
	return (nb_sort);
}

int		in_stk_a(t_stk *stk, int val, int i)
{
	int top;

	top = stk->top_a + 1;

	while (--top)
	{
		if (stk->stk_a[top] == val)
			return (1);
	}
	//ft_printf("pas dans A ! : stk->stk_a[%d] = %d, val[%d] = %d\n", top, stk->stk_a[top], i, val);
	//exit (1);
	return (0);
}
int		val_place(t_stk *stk, int val)
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

int		select_s_stk(t_stk *stk, int size)
{
	int tmp_stk[size];
	int rotate;
	int	rev_rotate;
	int i;

	i = 0;
	//if from b
	int j = -1;
	sort_tmp(tmp_stk, stk->stk_b, size, stk->top_b + 1);
	while (++j < size)
		ft_printf("tmpstk[%d] = %d\n", j, tmp_stk[j]);
	while (size - i > 0)
	{
	//	if (in_stk_a(stk, tmp_stk[i]))
	//		i++;
		if (stk->stk_b[stk->top_b] == tmp_stk[i])
		//		|| stk->stk_b[stk->top_b] == tmp_stk[i + 1])
		{
			ft_printf("Push de : %d\nQuand tmp_stk[%d] = %d", stk->stk_b[stk->top_b], i, tmp_stk[i]);
		//	if (!(in_stk_a(stk, tmp_stk[i])))
				ft_push(stk, 'b');
			if (in_stk_a(stk, tmp_stk[i], i))
				i++;
		}
		else
			{
				if (!(val_place(stk, tmp_stk[i])))
					ft_rotate(stk, stk->stk_b, stk->top_b, 'b');
				else
					ft_rev_rotate(stk, stk->stk_b, stk->top_b, 'b');
			}
		if (sorted(stk) != stk->top_a)
			sort_two_three(stk, 2);
	}
	return (0);
}

void	quick_sa_bis(t_stk *stk, int *size_b, int *size_a, int *b)
{
//	ft_printf("1 size_b[%d] = %d\nSize_a = %d\n", *b, size_b[*b], *size_a);
	if (*size_a <= 3 && sorted(stk) != stk->top_a)
	{
		if (stk->a_empty != 1)
			stk->a_empty = 1;
		*size_a = sort_two_three(stk, *size_a);
	}
	//if (stk->top_b && size_b[*b] <= 10 && size_b[*b] > 0)
	if (size_b[*b] <= 3 && size_b[*b] > 0)
	{
		if (size_b[*b] <= 3)
			*size_a = push_small_a(stk, &size_b[*b]);
		else	
		{
			size_b[*b] = select_s_stk(stk, size_b[*b]);
			//*size_a = 0;
		}
		if (*b > 1)
			*b -= 1;
	}
	else if (size_b[*b] > 1 && *size_a <= 1)
	{
		//ft_printf("size_b[%d] = %d\n", *b, size_b[*b]);
		*size_a = ft_to_a(stk, size_b[*b], *b);
		size_b[*b] = size_b[*b] - *size_a;
	}
	else if (*b > 1)
	{
		*b -= 1;
		size_b[*b] += 1;
	}
}

void	quick_s(t_stk *stk, int s_max)
{
	int size_a;
	int size_b[s_max];
	int b;

	b = 0;
	size_a = s_max;
	size_b[0] = 0;
	size_b[1] = 0;
	//int max = 800;
//	while (max-- && (sorted(stk) < s_max || size_b[1] != 0))
	while (sorted(stk) < s_max || size_b[1] != 0)
	{
		while (size_a > 3 && sorted(stk) != stk->top_a)
		{
			b++;
			size_b[b] = ft_to_b(stk, size_a, b);
			size_a = size_a - size_b[b];
		}
		quick_sa_bis(stk, size_b, &size_a, &b);
		if (sorted(stk) >= stk->top_a)
			size_a = 0;
		else
			size_a = stk->top_a - sorted(stk) + 1;
		write_stack(*stk, 1);
	}
	ft_printf((stk->inst + ft_strlen(stk->inst) - 30));
	while (1);
	//ft_printf("stk->stk_a[%d] = %d\n", stk->top_a, stk->stk_a[stk->top_a]);
}
