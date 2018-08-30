/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:34:11 by alanter           #+#    #+#             */
/*   Updated: 2018/08/29 16:47:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>

typedef struct	s_stk
{
	int 	*stk_a;
	int 	*stk_b;
	int 	*stk_s;
	int		top_a;
	int		top_b;
	char	*inst;
}				t_stk;

void    quicksort(int **tab, int low, int high);
void	selection_s(t_stk *stk, int size);
void    quick_sa(t_stk *stk, int s_max);
void    ft_swap(t_stk *stk, int *stack, int size, int select);
void    ft_rotate(t_stk *stk, int *stack, int size, int select);
void    ft_rev_rotate(t_stk *stk, int *stack, int size, int select);
void    ft_push(int *src, int *dst, int *top_s, int *top_d);
#endif
