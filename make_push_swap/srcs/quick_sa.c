/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:52:05 by alanter           #+#    #+#             */
/*   Updated: 2018/08/26 22:40:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_to_b(t_stk *stk)
{
	int med;

	med = stk->top_a / 2;
	ft_printf("med = %d\n", med);
	while (stk->top_a >= med)// && stk->top_a >= 3)// >= ?
	{
		if (stk->stk_a[stk->top_a] > stk->stk_s[med])
			ft_rotate(stk->stk_a, stk->top_a);
		else
		{
			ft_push(stk->stk_a, stk->stk_b, &stk->top_a, &stk->top_b);
			if (stk->stk_b[stk->top_b] == stk->stk_s[med])
				ft_rotate(stk->stk_b, stk->top_b);
		}	
	}
//	if (stk->top_a >= 3)
		ft_rev_rotate(stk->stk_b, stk->top_b);
}

void	quick_sa(t_stk *stk)
{
	while (stk->top_a >= 3)
		ft_to_b(stk);

}
