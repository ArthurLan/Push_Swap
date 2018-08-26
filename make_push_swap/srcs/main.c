/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:38:16 by alanter           #+#    #+#             */
/*   Updated: 2018/08/26 22:40:14 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	write_stack(t_stk stk, int argc);

static int	check_input(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (ft_atoll(argv[i]) > INT_MAX)
		{
			ft_printf("Error : one or several argument is too big. (max = 2 147 483 647)\n");
			return (-1);
		}
		while (argv[i][j] != 0)
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				ft_printf("Error : one or several argument isn't a number.\n");
				return (-1);
			}
			j++;
		}
		j = 0;
	}
	return (0);
}

static void	sort_s(t_stk *stk, int size)
{
	int i;

	i = -1;
	while (++i < size)
		stk->stk_s[i] = stk->stk_a[i];
	quicksort(&stk->stk_s, 0, size);
}

int		main(int argc, char **argv)
{
	t_stk	*stk;
	int		stack_a[argc - 1];
	int		stack_b[argc - 1];
	int		stack_s[argc - 1];
	int 	i = -1;

	stk = (t_stk*)ft_memalloc(sizeof(t_stk));
	stk->stk_a = stack_a;
	stk->stk_b = stack_b;
	stk->stk_s = stack_s;
	stk->top_a = argc - 2;
	stk->top_b = - 1;
	stk->inst = ft_memalloc(1);
	if (!(check_input(argc, argv)))
	{
		while (++i < argc - 1)
			stack_a[i] = ft_atoi(argv[argc - 1 -  i]);
		sort_s(stk, argc - 1);
		ft_printf("Voilà ma stack_a initialisée :\n");
		write_stack(*stk, argc);
	}
	//selection_s(stk, argc - 2);
	quick_sa(stk);
	write_stack(*stk, argc);
	//ft_printf("%s", stk->inst);
	return (0);
}



void	write_stack(t_stk stk, int argc)
{
	int i;

	i = -1;
	while (++i <= stk.top_a)
	{
		ft_printf("Voilà mon stack_a[%d] : %d\n", i, stk.stk_a[i]);
	}
	ft_putendl("");
	i = -1;
	while (++i <= stk.top_b)
	{
		ft_printf("Voilà mon stack_b[%d] : %d\n", i, stk.stk_b[i]);
	}
	i = -1;
	while (++i <= stk.top_a)
	{
		ft_printf("Voilà mon stk_s[%d] : %d\n", i, stk.stk_s[i]);
	}
}
