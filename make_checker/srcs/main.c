/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:30:53 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 05:16:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		sorted(t_stk *stk, int size)
{
	int nb_sort;

	nb_sort = 0;
	while (nb_sort + 1 < size && stk->stk_a[nb_sort + 1] < stk->stk_a[nb_sort])
		nb_sort++;
	if (nb_sort + 1 == size)
		ft_printf("OK\n");
	else
		ft_printf("KO\nnb_sort = %d, size = %d\n", nb_sort, size);
}

static void	exec(t_stk *stk, int i)
{
	void	(*ptr[4])(int *stack, int top);

	ptr[0] = ft_swap;
	ptr[1] = ft_rotate;
	ptr[2] = ft_rev_rotate;
	if (i < 3)
		(*ptr[i])(stk->stk_a, stk->top_a);
	else if (i < 6)
		(*ptr[i - 3])(stk->stk_b, stk->top_b);
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

void		inst(char *inst_in, t_stk *stk)
{
	int			i;
	static char	*inst[] = {"sa", "ra", "rra", "sb", "rb", "rrb", "ss", "rr",
		"rrr", "pa", "pb"};

	i = 0;
	while (i < 11)
	{
		if (!(ft_strcmp(inst[i], inst_in)))
			break ;
		i++;
	}
	if (i >= 11)
		ft_printf("Error : wrong instruction\n");
	else
		exec(stk, i);
}

static int	check_input(int argc, char **argv, t_stk *stk)
{
	int i;
	int j;

	i = 0;
	if (!(ft_strcmp(argv[1], "-v")) && (i += 1))
		stk->visual = 1;
	while (++i < argc)
	{
		j = -1;
		if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
		{
			ft_printf("Error : argument too big or too small. (int only)\n");
			return (-1);
		}
		while (argv[i][++j] != 0)
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'
						|| argv[i][j] == ' '))
			{
				ft_printf("Error : one or several argument isn't a number.\n");
				return (-1);
			}
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stk	*stk;

	if (argc < 1 || argv[1] == NULL)
		return (-1);
	if (!(stk = (t_stk*)ft_memalloc(sizeof(t_stk))))
		return (-1);
	if (!(check_input(argc, argv, stk)))
	{
		if ((stk->nb_values = init_t_stk(stk, argc, argv)) == -1)
			return (-1);
		if (stk->visual != 1)
		{
			while (get_next_line(0, &stk->inst) > 0)
			{
				inst(stk->inst, stk);
				free(stk->inst);
			}
			free(stk->inst);
		}
		else
			window(*stk);
	}
	sorted(stk, stk->nb_values);
	free(stk->stk_a);
	free(stk->stk_b);
	free(stk);
	return (0);
}
