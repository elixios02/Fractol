/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piximg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:49:57 by paim              #+#    #+#             */
/*   Updated: 2016/09/28 15:56:49 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int					color(t_data *t)
{
	double			c;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	c = (t->iter + 1) * 0.1;
	red = cos(c) * 127 + 128;
	green = cos(c + t->changecolor) * 127 + 128;
	blue = cos(c + (t->changecolor * 2)) * 127 + 128;
	return ((int)((red << 16)) + (int)((blue << 8)) + (int)(green));
}

void				ft_put_pixel_to_image2(t_data *t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t->img_color = mlx_get_color_value(t->mlx, color(t));
	if (t->y <= 0 || t->x <= 0 || t->x >= t->x_max || t->y >= t->y_max)
		return ;
	r = (t->img_color & 0xFF0000) >> 16;
	g = (t->img_color & 0xFF00) >> 8;
	b = (t->img_color & 0xFF) >> 0;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8] = b;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8 + 1] = g;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8 + 2] = r;
}

void				ft_put_pixel_to_image(t_data *t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t->img_color = mlx_get_color_value(t->mlx, 0x000000);
	if (t->y <= 0 || t->x <= 0 || t->x >= t->x_max || t->y >= t->y_max)
		return ;
	r = (t->img_color & 0xFF0000) >> 16;
	g = (t->img_color & 0xFF00) >> 8;
	b = (t->img_color & 0xFF) >> 0;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8] = b;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8 + 1] = g;
	t->data[t->y * t->sizeline + t->x * t->bpp / 8 + 2] = r;
}
