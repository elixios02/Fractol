/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:46:02 by paim              #+#    #+#             */
/*   Updated: 2016/09/30 18:50:43 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88
# define SEVEN 89
# define EIGHT 91

typedef struct		s_data
{
	int				juju;
	int				numf;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	img_color;
	int				x_max;
	int				y_max;
	int				x;
	int				y;
	double			tmp;
	double			xmn;
	double			xmx;
	double			ymn;
	double			ymx;
	double			zx;
	double			zy;
	double			r;
	double			c;
	double			cr;
	double			ci;
	int				iter;
	int				itemax;
	int				trig;
	double			changecolor;
}					t_data;

t_data		*init_struct_fract(char *argv);
t_data		*init_struct_mandel(t_data *t);
t_data		*init_struct_tricorn(t_data *t);
t_data		*init_struct_burningship(t_data *t);
t_data		*init_struct_julia(t_data *t);
int			error(const char *str);
void		ft_put_pixel_to_image(t_data *t);
void		ft_put_pixel_to_image2(t_data *t);
int			ft_dbwhile(t_data *t);
void		mandelbrot(t_data *t);
void		mandelballoon(t_data *t);
void		mandelbomb(t_data *t);
void		julia(t_data *t);
void		julia2(t_data *t);
void		julia3(t_data *t);
void		tricorn(t_data *t);
void		burningship(t_data *t);
int			ft_mouse_hook(int keycode, int x, int y, t_data *t);
int			color(t_data *t);
int			keyscroll(int keycode, int x, int y, t_data *t);
int			ft_key_hook(int keycode, t_data *t);
int			ft_key_hook2(int keycode, t_data *t);
int			ft_key_hook3(int keycode, t_data *t);
int			motionnotify(int x, int y, t_data *t);
int			check_arg(char **argv);
void		select_fract(t_data *t);
void		give_first_fracte(char ** argv, t_data *t);
void		init_snde_fract(t_data *t);
void		manuel(void);
void		manuel2(void);

#endif
