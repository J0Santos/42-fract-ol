/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:35:14 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 00:11:56 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}

t_pxl	mandelbrot_set(int x, int y, t_view *view)
{
	t_pxl		pixel;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex(x, y, view);
	c = z;
	while (z.re * z.re + z.im * z.im < (1 << 8) && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			i = view->precision;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		i++;
	}
	pixel.pixel = z;
	pixel.iter = i;
	return (pixel);
}
