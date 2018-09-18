/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:02 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 05:00:44 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_s(t_stk *stk, int size)
{
	int i;

	i = -1;
	while (++i < size)
		stk->stk_s[i] = stk->stk_a[i];
	quicksort(&stk->stk_s, 0, size);
}

static int		parse_arg(int argc, char **argv, t_stk *stk)
{
	int		nb_values;
	char	*str_arg;

	if (ft_strlen(argv[1]) != 0 && ft_strcmp(argv[1], "-s") == 0)
		stk->option = 1;
	if (stk->option == 1)
		str_arg = argv[2];
	else
		str_arg = argv[1];
	if (argc == 2 || (stk->option == 1 && argc == 3))
	{
		stk->arg = 1;
		nb_values = ft_wordcounter(str_arg, ' ');
	}
	else
		nb_values = argc - 1 - stk->option;
	return (nb_values);
}

static int		check_dbl(int *top, int stored_val, int new_nb)
{
	while (stored_val--)
	{
		if (top[stored_val] == new_nb)
		{
			ft_printf("Error : a number can't be there twice\n");
			return (1);
		}
	}
	return (0);
}

static int		init_stk_a(t_stk *stk, int argc, char **argv, int nb_values)
{
	static int	i = -1;
	static int	k = 0;

	if (stk->arg == 1)
	{
		while (++i < nb_values && argv[1][k] != 0)
		{
			if (check_dbl(&stk->stk_a[nb_values - i], i, ft_atoi(&argv[1][k])))
				return (1);
			stk->stk_a[nb_values - 1 - i] = ft_atoi(&argv[1][k]);
			while (argv[1][k] != ' ' && argv[1][k] != 0)
				k++;
			while (argv[1][k] == ' ' && argv[1][k] != 0)
				k++;
		}
	}
	while (++i < nb_values)
	{
		if (check_dbl(stk->stk_a, i, ft_atoi(argv[argc - 1 - i])))
			return (1);
		stk->stk_a[i] = ft_atoi(argv[argc - 1 - i]);
	}
	sort_s(stk, nb_values);
	return (0);
}

int				init_t_stk(t_stk *stk, int argc, char **argv)
{
	int nb_values;

	nb_values = parse_arg(argc, argv, stk);
	if (!(stk->stk_a = (int*)ft_memalloc(sizeof(int*) * nb_values)))
		return (-1);
	if (!(stk->stk_b = (int*)ft_memalloc(sizeof(int*) * nb_values)))
		return (-1);
	if (!(stk->stk_s = (int*)ft_memalloc(sizeof(int*) * nb_values)))
		return (-1);
	stk->top_a = nb_values - 1;
	stk->top_b = -1;
	stk->inst = ft_memalloc(1);
	stk->max = 150;
	if (init_stk_a(stk, argc, argv, nb_values))
		return (-1);
	return (nb_values);
}
