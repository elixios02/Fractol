/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:57:47 by paim              #+#    #+#             */
/*   Updated: 2016/10/11 19:39:13 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

t_data		*init_struct_burningship(t_data *t)
{
	t->juju = 0;
	t->xmn = -2;
	t->xmx = 0.5;
	t->ymn = -1.25;
	t->ymx = 1.25;
	t->zx = t->x_max / (t->xmx - t->xmn);
	t->zy = t->y_max / (t->ymx - t->ymn);
	t->itemax = 50;
	t->changecolor = 14;
	return (t);
}

t_data		*init_struct_mandel(t_data *t)
{
	t->juju = 0;
	t->xmn = -2.2;
	t->xmx = 0.7;
	t->ymn = -1.25;
	t->ymx = 1.25;
	t->zx = t->x_max / (t->xmx - t->xmn);
	t->zy = t->y_max / (t->ymx - t->ymn);
	t->itemax = 50;
	t->changecolor = 13;
	return (t);
}

t_data		*init_struct_tricorn(t_data *t)
{
	t->juju = 0;
	t->xmn = -2;
	t->xmx = 2;
	t->ymn = -2;
	t->ymx = 2;
	t->zx = t->x_max / (t->xmx - t->xmn);
	t->zy = t->y_max / (t->ymx - t->ymn);
	t->itemax = 50;
	t->changecolor = 17;
	return (t);
}

t_data		*init_struct_julia(t_data *t)
{
	t->juju = 1;
	t->xmn = -1;
	t->xmx = 1;
	t->ymn = -1.2;
	t->ymx = 1.2;
	t->cr = 0.00000;
	t->ci = 0.00000;
	t->zx = t->x_max / (t->xmx - t->xmn);
	t->zy = t->y_max / (t->ymx - t->ymn);
	t->itemax = 50;
	t->changecolor = 71;
	t->trig = 0;
	return (t);
}

t_data		*init_struct_fract(char *argv)
{
	t_data	*t;

	t = (t_data *)ft_memalloc(sizeof(t_data));
	t->y_max = 800;
	t->x_max = 800;
	t->trig = 1;
	if ((ft_strcmp(argv, "Mandelbrot") == 0) ||
			(ft_strcmp(argv, "Mandelbomb") == 0) ||
			(ft_strcmp(argv, "Mandelballoon") == 0))
		t = init_struct_mandel(t);
	if (ft_strcmp(argv, "Julia") == 0 || (ft_strcmp(argv, "Julia2") == 0) ||
			(ft_strcmp(argv, "Julia3") == 0))
		t = init_struct_julia(t);
	if (ft_strcmp(argv, "Tricorn") == 0)
		t = init_struct_tricorn(t);
	if (ft_strcmp(argv, "Burningship") == 0)
		t = init_struct_burningship(t);
	return (t);
}
