/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:43:45 by paim              #+#    #+#             */
/*   Updated: 2016/10/31 16:32:39 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int			keyscroll(int keycode, int x, int y, t_data *t)
{
	double	x1;
	double	y1;

	if (y > 0)
	{
		x1 = ((double)x / t->zx + t->xmn);
		y1 = ((double)y / t->zy + t->ymn);
		if (keycode == 4)
		{
			t->zx *= 1.1;
			t->zy *= 1.1;
			t->xmn = x1 - ((double)x / t->zx);
			t->ymn = y1 - ((double)y / t->zy);
			t->itemax += 10;
		}
		else if (keycode == 5)
		{
			t->zx *= 0.9;
			t->zy *= 0.9;
			t->xmn = x1 - ((double)x / t->zx);
			t->ymn = y1 - ((double)y / t->zy);
			t->itemax -= 10;
		}
	}
	return (0);
}

int			motionnotify(int x, int y, t_data *t)
{
	double	i;

	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	t->img = mlx_new_image(t->mlx, t->x_max, t->y_max);
	i = 0.03;
	if (x > 0 && x <= t->x_max && y > 0 && y <= t->y_max)
		if (t->juju == 1 && t->trig % 2 == 0)
		{
			if (x < t->x_max / 2 && y < t->y_max / 2)
				t->cr += i;
			if (x > t->x_max / 2 && y < t->y_max / 2)
				t->cr -= i;
			if (x < t->x_max / 2 && y > t->y_max / 2)
				t->ci += i;
			if (x > t->x_max / 2 && y > t->y_max / 2)
				t->ci -= i;
		}
	ft_dbwhile(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}

int			ft_mouse_hook(int keycode, int x, int y, t_data *t)
{
	if (keycode == 1)
		t->trig++;
	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_image(t->mlx, t->img);
	keyscroll(keycode, x, y, t);
	t->img = mlx_new_image(t->mlx, t->x_max, t->y_max);
	ft_dbwhile(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}
