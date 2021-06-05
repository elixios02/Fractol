/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manuel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:52:26 by paim              #+#    #+#             */
/*   Updated: 2016/09/30 18:56:42 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

void	manuel2(void)
{
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tZOOM\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t* + Zoom\n");
	ft_putstr("\t\t* - Dezoom\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t RESET\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t* R\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tCLICK TO STOP MOUSE FOR JULIA\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tMOOVE IN THE FRACTALE WITH ARROWS\n");
}

void	manuel(void)
{
	ft_putstr("\t\tList of keys :\n\n\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tMODIF MAXIMUM ITERATION\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t*  / -10 au maximum d iteration\n");
	ft_putstr("\t\t*  * +10 au maximm d iteration\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tMODIF COLORS\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t*  P \n");
	ft_putstr("\t\t*  O \n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\tCHANGE FRACTAL\n");
	ft_putstr("\t\t-----------------------------------\n");
	ft_putstr("\t\t*  1 Julia \n");
	ft_putstr("\t\t*  2 Julia2\n");
	ft_putstr("\t\t*  3 Julia3\n");
	ft_putstr("\t\t*  4 Mandelbrot\n");
	ft_putstr("\t\t*  5 Mandelballoon\n");
	ft_putstr("\t\t*  6 Mandelbomb\n");
	ft_putstr("\t\t*  7 Tricorn\n");
	ft_putstr("\t\t*  8 Burningship\n");
	manuel2();
}
