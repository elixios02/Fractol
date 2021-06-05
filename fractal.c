/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 17:03:21 by paim              #+#    #+#             */
/*   Updated: 2017/01/16 17:24:34 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	julia3(t_data *t)
{
	double	real;
	double	img;
	double	x;

	t->iter = 0;
	real = t->x / t->zx + t->xmn;
	img = t->y / t->zy + t->ymn;
	while ((real * real + img * img) < 4 && t->iter < t->itemax)
	{
		x = real;
		real = real * real - img * img + t->cr;
		img = (5 * x * img) + t->ci;
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void	julia2(t_data *t)
{
	double	real;
	double	img;
	double	x;

	t->iter = 0;
	real = t->x / t->zx + t->xmn;
	img = t->y / t->zy + t->ymn;
	while ((real * real + img * img) < 4 && t->iter < t->itemax)
	{
		x = real;
		real = fabs(real * real - img * img + t->cr);
		img = fabs((2 * x * img) + t->ci);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void	tricorn(t_data *t)
{
	t->iter = 0;
	t->r = 0;
	t->c = 0;
	while (t->r * t->r + t->c * t->c < 4 && t->iter < t->itemax)
	{
		t->tmp = t->r;
		t->r = t->r * t->r - t->c * t->c + (t->x / t->zx + t->xmn);
		t->c = -2 * t->c * t->tmp + (t->y / t->zy + t->ymn);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void	select_fract(t_data *t)
{
	if (t->numf == ONE)
		julia(t);
	if (t->numf == TWO)
		julia2(t);
	if (t->numf == THREE)
		julia3(t);
	if (t->numf == FOUR)
		mandelbrot(t);
	if (t->numf == FIVE)
		mandelballoon(t);
	if (t->numf == SIX)
		mandelbomb(t);
	if (t->numf == SEVEN)
		tricorn(t);
	if (t->numf == EIGHT)
		burningship(t);
}

int		ft_dbwhile(t_data *t)
{
	t->y = 0;
	while (t->y != t->y_max)
	{
		t->x = 0;
		while (t->x != t->x_max)
		{
			select_fract(t);
			t->x++;
		}
		t->y++;
	}
	return (0);
}
