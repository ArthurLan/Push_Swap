/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:30:53 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 23:23:36 by alanter          ###   ########.fr       */
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
		ft_printf("KO\n");
}

static int	check_input_b(char **argv, int i)
{
	if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
	{
		write(2, "Error : int only.\n", 18);
		return (-1);
	}
	return (0);
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
		if (check_input_b(argv, i) == -1)
			return (-1);
		while (argv[i][++j] != 0)
		{
			if (argv[i][0] == '"' && ft_strlen(argv[i] - 1) == '"' && j++)
				argv[i][ft_strlen(argv[i] - 1)] = ' ';
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
						|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			{
				write(2, "Error : numbers only (int only).\n", 33);
				return (-1);
			}
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_stk	*stk;

	if (ac < 1 || av[1] == NULL || !(stk = (t_stk*)ft_memalloc(sizeof(t_stk))))
		return (-1);
	if (!(check_input(ac, av, stk)))
	{
		if ((stk->nb_values = init_t_stk(stk, ac, av)) == -1)
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
		sorted(stk, stk->nb_values);
	}
	free(stk->stk_a);
	free(stk->stk_b);
	free(stk);
	return (0);
}
