/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:14:47 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 16:15:01 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*init_fractal(char *str)
{
	t_fractal *fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		ft_error("Error malloc");
	if (ft_strncmp(str, "Mandelbrot", 10) == 0)
		*fractal = (t_fractal){"Mandelbrot", mandelbrot_set};
	else if (ft_strncmp(str, "Julia", 5) == 0)
		*fractal = (t_fractal){"Julia", julia_set};
	else
		ft_error("Allowed fractals:\n\tMandelbrot;\n\tJulia;\n");
	return (fractal);
}

void	pixels_to_image(t_control *control)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->heigth)
		{
			color = get_color((control->pixels + y  * WIDTH + x)->iter, control->view.precision, control->view.color);
			my_mlx_pixel_put(control->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(control->mlx, control->win, control->img->img, 0, 0);
}

void	render_fractal(t_control *control)
{
	int	x;
	int	y;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->heigth)
		{
			*(control->pixels + y * WIDTH + x) = control->fractal->fn_fractal(x,
				y, &control->view);
			y++;
		}
		x++;
	}
	pixels_to_image(control);
}
