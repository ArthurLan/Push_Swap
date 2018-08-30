/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:24:02 by alanter           #+#    #+#             */
/*   Updated: 2018/08/21 12:29:16 by alanter          ###   ########.fr       */
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
	int		top_a;
	int		top_b;
	char	*inst;
}				t_stk;

void	ft_swap(int *stack, int size);
void	ft_rotate(int *stack, int size);
void	ft_rev_rotate(int *stack, int size);
void    ft_push(int *src, int *dst, int *top_s, int *top_d);

#endif
