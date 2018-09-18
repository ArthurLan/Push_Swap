/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:34:11 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 23:44:24 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct	s_stk
{
	int		*stk_a;
	int		*stk_b;
	int		*stk_s;
	int		top_a;
	int		top_b;
	char	*inst;
	int		option;
	int		arg;
	int		a_empty;
	int		select_s;
	int		max;
}				t_stk;

void			quicksort(int **tab, int low, int high);
void			select_s(t_stk *stk, int size);
void			quick_s(t_stk *stk, int s_max);
void			quick_s_max(t_stk *stk, int s_max);
void			ft_swap(t_stk *stk, int *stack, int size, int select);
void			ft_rotate(t_stk *stk, int *stack, int size, int select);
void			ft_rev_rotate(t_stk *stk, int *stack, int size, int select);
void			ft_push(t_stk *stk, int select);
int				ft_to_b(t_stk *stk, int size);
int				ft_to_a(t_stk *stk, int size_b, int b);
int				push_small_a(t_stk *stk, int *size_b);
int				sort_two_three(t_stk *stk, int size);
char			*reducepa(char *str);
char			*reducepb(char *str);
char			*reducerr(char *str);
char			*reducess(char *str);
char			*reducerrr(char *str);
char			*reduce_dbl_r(char *str);
int				init_t_stk(t_stk *stk, int argc, char **argv);
void			sort_tmp(int *tmp_stk, int *src_stk, int size, int top);
int				sorted(t_stk *stk);

#endif
