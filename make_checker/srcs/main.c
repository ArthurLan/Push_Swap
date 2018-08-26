/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:30:53 by alanter           #+#    #+#             */
/*   Updated: 2018/08/26 22:40:32 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
void	write_stack(t_stk stk, int argc);

static void	exec(t_stk *stk, int i)
{
	void	(*ptr[4])(int *stack, int top);

	ptr[0] = ft_swap;
	ptr[1] = ft_rotate;
	ptr[2] = ft_rev_rotate;
	if (i < 3)
		(*ptr[i])(stk->stk_a, stk->top_a);
	else if (i < 6)
		(*ptr[i - 3])(stk->stk_b,stk->top_b);
	else if (i < 9)
	{
		(*ptr[i - 6])(stk->stk_a, stk->top_a);
		(*ptr[i - 6])(stk->stk_b, stk->top_b);
	}
	else if (i == 9)
		ft_push(stk->stk_b, stk->stk_a, &(stk->top_b), &(stk->top_a));
	else if (i == 10)
		ft_push(stk->stk_a, stk->stk_b, &(stk->top_a), &(stk->top_b));
}

static void	inst(char *inst_in, t_stk *stk)
{
	int i = 0;
	static char *inst[] = {"sa", "ra", "rra", "sb", "rb", "rrb", "ss", "rr",
		"rrr", "pa", "pb"};

	while (i < 11)
	{
		if (!(ft_strcmp(inst[i], inst_in)))
			break;
		i++;		
	}
	if (i >= 11)
		ft_printf("Error : wrong instruction\n");
	else
		exec(stk, i);
}

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

int		main(int argc, char **argv)
{
	t_stk	*stk;
	int		stack_a[argc - 1];
	int		stack_b[argc - 1];
	int 	i = -1;

	stk = (t_stk*)ft_memalloc(sizeof(t_stk));
	stk->stk_a = stack_a;
	stk->stk_b = stack_b;
	stk->top_a = argc - 2;
	stk->top_b = - 1;
	if (!(check_input(argc, argv)))
	{
		while (++i < argc - 1)
			stack_a[i] = ft_atoi(argv[argc - 1 -  i]);
		ft_printf("Voilà ma stack_a initialisée :\n");
		write_stack(*stk, argc);
		while (get_next_line(0, &stk->inst) > 0)
		{
			inst(stk->inst, stk);
//			write_stack(*stk, argc);
		}
	}
	write_stack(*stk, argc);
	return (0);
}


//ft_printf(">>> top_1 = %d <<<<\n\n", stk->top_a);
//ft_printf(">>> argc = %d <<<<\n\n", argc);




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

}


//	ft_printf("mon top_a prev = %d\n", stk->top_a);
//	ft_printf("mon top_b prev = %d\n", *(&(stk->top_b)));
//	ft_printf("mon top_a post = %d\n", stk->top_a);
//	ft_printf("mon top_b post = %d\n", stk->top_b);
