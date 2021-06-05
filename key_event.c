/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:02:24 by paim              #+#    #+#             */
/*   Updated: 2016/10/22 18:21:42 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int		ft_key_hook3(int keycode, t_data *t)
{
	if (keycode == 69)
	{
		t->zx = t->zx + 1000;
		t->zy = t->zy + 1000;
	}
	if (keycode == 9)
	{
		t->xmx = t->xmx - 0.01;
		t->ymx = t->ymx - 0.01;
		t->xmn = t->xmn + 0.01;
		t->ymn = t->ymn + 0.01;
	}
	if (keycode == 78)
	{
		t->zx = t->zx - 1000;
		t->zy = t->zy - 1000;
	}
	if (keycode == 31)
	{
		if (t->changecolor > 1)
			t->changecolor--;
	}
	return (0);
}

int		ft_key_hook2(int keycode, t_data *t)
{
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == 126)
	{
		t->ymn = t->ymn - 0.1;
		t->ymx = t->ymx + 0.1;
	}
	if (keycode == 123)
	{
		t->xmn = t->xmn - 0.1;
		t->ymx = t->xmx + 0.1;
	}
	if (keycode == 124)
	{
		t->xmn = t->xmn + 0.1;
		t->xmx = t->xmx - 0.1;
	}
	if (keycode == 125)
	{
		t->ymn = t->ymn + 0.1;
		t->ymx = t->ymx - 0.1;
	}
	if (keycode == 67)
		t->itemax += 10;
	if (keycode == 75)
		t->itemax -= 10;
	return (0);
}

void	init_snde_fract(t_data *t)
{
	if (t->numf == ONE || t->numf == TWO || t->numf == THREE)
		t = init_struct_julia(t);
	if (t->numf == FOUR || t->numf == FIVE || t->numf == SIX)
		t = init_struct_mandel(t);
	if (t->numf == SEVEN)
		t = init_struct_tricorn(t);
	if (t->numf == EIGHT)
		t = init_struct_burningship(t);
}

int		ft_key_hook(int keycode, t_data *t)
{
	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	if (keycode == 15)
		init_snde_fract(t);
	if ((keycode >= ONE && keycode <= SEVEN) || keycode == EIGHT)
	{
		t->numf = keycode;
		init_snde_fract(t);
	}
	if (keycode == 53)
		exit(EXIT_FAILURE);
	if (keycode == 35)
		t->changecolor++;
	else
	{
		ft_key_hook2(keycode, t);
		ft_key_hook3(keycode, t);
	}
	t->img = mlx_new_image(t->mlx, t->x_max, t->y_max);
	ft_dbwhile(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}
