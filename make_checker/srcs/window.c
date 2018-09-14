/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:43 by alanter           #+#    #+#             */
/*   Updated: 2018/09/13 04:39:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_new_image(t_mlx *mlx, t_stk stk, int val_h)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	draw_back(mlx->img.img);
	draw_stka(mlx->img.img, stk, val_h);
	draw_stkb(mlx->img.img, stk, val_h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	draw_str(mlx);
}

int			loop_sort(t_mlx *mlx)
{
	int			val_h;
	static int	i;

	val_h = WIN_H / mlx->stk.nb_values;
	i = 0;
	if ((mlx->ok = get_next_line(0, &(mlx->stk.inst))) > 0)
	{
		inst(mlx->stk.inst, &(mlx->stk));
		if (mlx->speed >= 50)
		{
			usleep(mlx->speed);
			ft_new_image(mlx, mlx->stk, val_h);
		}
		else if (mlx->stk.top_a % 5 == 0
				|| mlx->stk.top_a >= mlx->stk.max - 3)
			ft_new_image(mlx, mlx->stk, val_h);
	}
	if (mlx->ok == 0 && (mlx->print_ok = 1))
		ft_new_image(mlx, mlx->stk, val_h);
	return (0);
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 124)
	{
		if (mlx->speed >= 50)
			mlx->speed /= 10;
		mlx_loop_hook(mlx->mlx_ptr, loop_sort, mlx);
	}
	if (key == 123)
	{
		if (mlx->speed < 500000)
			mlx->speed *= 10;
		mlx_loop_hook(mlx->mlx_ptr, loop_sort, mlx);
	}
	if (key == 53)
		exit(0);
	return (0);
}

int			store_max_w(t_stk stk)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i <= stk.top_a)
	{
		if (abs(stk.stk_a[i]) > max)
			max = abs(stk.stk_a[i]);
		i++;
	}
	return (max);
}

void		*window(t_stk stk)
{
	t_mlx	*mlx;
	int		val_h;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	val_h = WIN_H / stk.nb_values;
	mlx->speed = 500000;
	stk.max = store_max_w(stk);
	mlx->stk = stk;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Push_swap");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	draw_back(mlx->img.img);
	draw_stka(mlx->img.img, stk, val_h);
	draw_stkb(mlx->img.img, stk, val_h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	draw_str(mlx);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (mlx->mlx_ptr);
}
