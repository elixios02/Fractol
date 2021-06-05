/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:04:33 by paim              #+#    #+#             */
/*   Updated: 2016/09/30 18:57:29 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void		burningship(t_data *t)
{
	t->iter = 0;
	t->r = 0;
	t->c = 0;
	while (t->r * t->r + t->c * t->c < 4 && t->iter < t->itemax)
	{
		t->tmp = t->r;
		t->r = t->r * t->r - t->c * t->c + (t->x / t->zx + t->xmn);
		t->c = 2 * fabs(t->c) * fabs(t->tmp) + (t->y / t->zy + t->ymn);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void		mandelbrot(t_data *t)
{
	t->iter = 0;
	t->r = 0;
	t->c = 0;
	while (t->r * t->r + t->c * t->c < 4 && t->iter < t->itemax)
	{
		t->tmp = t->r;
		t->r = t->r * t->r - t->c * t->c + (t->x / t->zx + t->xmn);
		t->c = 2 * t->c * t->tmp + (t->y / t->zy + t->ymn);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void		mandelballoon(t_data *t)
{
	t->iter = 0;
	t->r = 0;
	t->c = 0;
	while (t->r * t->r + t->c * t->c < 4 && t->iter < t->itemax)
	{
		t->tmp = t->r;
		t->r = t->r * t->r - t->c * t->c + (t->x / t->zx + t->xmn);
		t->c = sqrt(6) * t->c * t->tmp + (t->y / t->zy + t->ymn);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void		mandelbomb(t_data *t)
{
	t->iter = 0;
	t->r = 0;
	t->c = 0;
	while (t->r * t->r + t->c * t->c < 4 && t->iter < t->itemax)
	{
		t->tmp = t->r;
		t->r = t->r * t->r - t->c * t->c + (t->x / t->zx + t->xmn);
		t->c = 5 * t->c * t->tmp + (t->y / t->zy + t->ymn);
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}

void		julia(t_data *t)
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
		img = (2 * x * img) + t->ci;
		t->iter++;
	}
	if (t->iter == t->itemax)
		ft_put_pixel_to_image(t);
	else
		ft_put_pixel_to_image2(t);
}
