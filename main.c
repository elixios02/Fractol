/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:33:22 by paim              #+#    #+#             */
/*   Updated: 2016/10/20 15:45:32 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	give_first_fract(char **argv, t_data *t)
{
	if (ft_strcmp(argv[1], "Julia") == 0)
		t->numf = ONE;
	if (ft_strcmp(argv[1], "Julia2") == 0)
		t->numf = TWO;
	if (ft_strcmp(argv[1], "Julia3") == 0)
		t->numf = THREE;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		t->numf = FOUR;
	if (ft_strcmp(argv[1], "Mandelballoon") == 0)
		t->numf = FIVE;
	if (ft_strcmp(argv[1], "Mandelbomb") == 0)
		t->numf = SIX;
	if (ft_strcmp(argv[1], "Tricorn") == 0)
		t->numf = SEVEN;
	if (ft_strcmp(argv[1], "Burningship") == 0)
		t->numf = EIGHT;
}

int		check_arg(char **argv)
{
	if ((ft_strequ(argv[1], "Julia") != 1) &&
			(ft_strequ(argv[1], "Julia2") != 1) &&
			(ft_strequ(argv[1], "Julia3") != 1) &&
			(ft_strequ(argv[1], "Mandelbrot") != 1) &&
			(ft_strequ(argv[1], "Mandelballoon") != 1) &&
			(ft_strequ(argv[1], "Mandelbomb") != 1) &&
			(ft_strequ(argv[1], "Tricorn") != 1) &&
			(ft_strequ(argv[1], "Burningship") != 1))
		return (error("Bad argument. RTFM"));
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*t;

	if (argc != 2)
		return (error("You need 2 argument"));
	if (check_arg(argv) != 0)
		return (0);
	t = init_struct_fract(argv[1]);
	give_first_fract(argv, t);
	manuel();
	if ((t->mlx = mlx_init()) == NULL)
		return (0);
	t->win = mlx_new_window(t->mlx, t->x_max, t->y_max, "Fractol");
	t->img = mlx_new_image(t->mlx, t->x_max, t->y_max);
	t->data = mlx_get_data_addr(t->img, &t->bpp, &t->sizeline, &t->endian);
	ft_dbwhile(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_hook(t->win, 6, 1 << 6, motionnotify, t);
	mlx_hook(t->win, 4, 64, ft_mouse_hook, t);
	mlx_hook(t->win, 2, 64, ft_key_hook, t);
	mlx_loop(t->mlx);
	return (0);
}
