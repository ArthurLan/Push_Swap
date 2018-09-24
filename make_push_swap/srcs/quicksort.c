/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:16:19 by alanter           #+#    #+#             */
/*   Updated: 2018/09/18 03:37:01 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		quicksort(int **tab, int low, int high)
{
	int i;
	int j;
	int pivot;

	i = low - 1;
	j = low - 1;
	if (high - 1 >= 0)
	{
		pivot = tab[0][high - 1];
		if (low < high)
		{
			while (++j < high - 1)
			{
				if (tab[0][j] > pivot)
				{
					i++;
					if (i != j)
						swap(&tab[0][j], &tab[0][i]);
				}
			}
			swap(&tab[0][j], &tab[0][i + 1]);
			quicksort(tab, low, i + 1);
			quicksort(tab, i + 2, high);
		}
	}
}
