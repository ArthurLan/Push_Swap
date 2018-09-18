/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:38:16 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 23:41:19 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_input_b(char **argv, int i)
{
	if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
	{
		write(2, "Error : int only.\n", 18);
		return (-1);
	}
	return (0);
}

static int		check_input(int argc, char **argv, t_stk *stk, int i)
{
	int j;

	if (!(ft_strcmp(argv[1], "-s")) && (i += 1))
		stk->select_s = 1;
	while (++i < argc)
	{
		j = -1;
		if (check_input_b(argv, i) == -1)
			return (-1);
		while (argv[i][++j] != 0)
		{
			if (argv[i][0] == '"' && j == 0)
				j++;
			if (ft_strlen(argv[i] - 1) == '"'
					&& j == (int)ft_strlen(argv[i] - 1))
				break ;
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
						|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			{
				write(2, "error : numbers only (int only).\n", 33);
				return (-1);
			}
		}
	}
	return (0);
}

static void		improve(t_stk *stk)
{
	char	*tmp_a;
	char	*tmp_b;

	tmp_a = reducepa(stk->inst);
	free(stk->inst);
	tmp_b = reducepb(tmp_a);
	free(tmp_a);
	tmp_a = reduce_dbl_r(tmp_b);
	free(tmp_b);
	tmp_b = reducerr(tmp_a);
	free(tmp_a);
	tmp_a = reducess(tmp_b);
	free(tmp_b);
	tmp_b = reducerrr(tmp_a);
	free(tmp_a);
	stk->inst = tmp_b;
}

void			clean_free(t_stk *stk)
{
	free(stk->stk_a);
	free(stk->stk_b);
	free(stk->stk_s);
	free(stk->inst);
	free(stk);
}

int				main(int argc, char **argv)
{
	t_stk	*stk;
	int		nb_values;

	if (argc > 1 && argv[1] != NULL)
	{
		if (!(stk = (t_stk*)ft_memalloc(sizeof(t_stk))))
			return (-1);
		if (!(check_input(argc, argv, stk, 0)))
		{
			if ((nb_values = init_t_stk(stk, argc, argv)) == -1)
				return (-1);
			if (nb_values > 0)
			{
				if (stk->select_s == 1 || nb_values <= 25)
					select_s(stk, nb_values);
				else
					quick_s(stk, nb_values);
				improve(stk);
				ft_printf(stk->inst);
			}
			clean_free(stk);
		}
	}
	return (0);
}
