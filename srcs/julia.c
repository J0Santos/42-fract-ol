/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:02:58 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 00:11:55 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex_julia(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}

t_pxl	julia_set(int x, int y, t_view *view)
{
	t_pxl		pixel;
	t_complex	z;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex_julia(x, y, view);
	while (z.re * z.re + z.im * z.im < (1 << 8) && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + view->mouse.re;
		temp.im = z.re * z.im * 2 + view->mouse.im;
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
