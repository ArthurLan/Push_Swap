/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:25:21 by alanter           #+#    #+#             */
/*   Updated: 2018/09/13 04:38:20 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	draw_str(t_mlx *mlx)
{
	int c;

	c = 0x000000;
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 4 - 5, 10, c, "STK_A");
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W * 3 / 4 - 5, 10, c, "STK_B");
	if (mlx->speed < 5)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100000");
	else if (mlx->speed < 50)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10000");
	else if (mlx->speed < 500)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1000");
	else if (mlx->speed < 5000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100");
	else if (mlx->speed < 50000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10");
	else if (mlx->speed < 500000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1");
	else if (mlx->speed < 5000000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X0.1");
	if (mlx->print_ok == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 2, WIN_H / 2, c, "OK");
}

void	draw_back(unsigned int *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < WIN_W)
	{
		while (y < WIN_H)
		{
			if ((x < WIN_W / 2))
				img[y * WIN_W + x] = 0xFEBDC0;
			else
				img[y * WIN_W + x] = 0xB3E5EE;
			y++;
		}
		x++;
		y = 0;
	}
}

void	draw_stkb(unsigned int *img, t_stk stk, int val_h)
{
	int x;
	int y;
	int val_w;

	x = WIN_W / 2;
	y = 0;
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			val_w = abs(stk.stk_b[stk.top_b] * WIN_W / 2 / stk.max);
			if (y > WIN_H - ((stk.top_b + 1) * val_h) && x - WIN_W / 2 < val_w)
			{
				if (stk.stk_b[stk.top_b] > 0)
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = 0x44B2C7;
				else
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = 0x44B200;
			}
			if (y > WIN_H - ((stk.top_b) * val_h))
				stk.top_b -= 1;
			x++;
		}
		y++;
		x = WIN_W / 2;
	}
}

void	draw_stka(unsigned int *img, t_stk stk, int val_h)
{
	int x;
	int y;
	int val_w;
	int top;

	x = 0;
	y = -1;
	top = stk.top_a;
	while (++y < WIN_H && x < WIN_W / 2)
	{
		while (++x < WIN_W)
		{
			val_w = abs(stk.stk_a[top] * WIN_W / 2 / stk.max);
			if (y > WIN_H - ((top + 1) * val_h) && x < val_w)
			{
				if (stk.stk_a[stk.top_a] < 0)
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = 0xFB515D;
				else
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = 0xFB5100;
			}
			if (y > WIN_H - ((top) * val_h))
				top -= 1;
		}
		x = -1;
	}
}
