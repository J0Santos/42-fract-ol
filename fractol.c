/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:59:31 by josantos          #+#    #+#             */
/*   Updated: 2021/10/13 13:04:47 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from keyhook number: %d!\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Hello from mousehook. Button %d and coordinates %d, %d\n", button, x, y);
	return (0);
}
*/
void	check_input(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		ft_error("Minimum params must be: ./fractol <fractal name>\n");
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		data->fractal_name = "Mandelbrot";
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		data->fractal_name = "Julia";
	else
		ft_error("Allowed fractal sets: Mandelbrot; Julia;\n");
}

void	do_fractal(t_data *data)
{
	if (ft_strncmp(data->fractal_name, "M", 1) == 0)
		draw_mandelbrot(data);
	else
		draw_julia(data);
		
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_input(argc, argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, data.fractal_name);
	data.img->img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bpp, 
		&data.img->line_length, &data.img->endian);
	do_fractal(&data);
	mlx_loop(data.mlx);
	ft_error("Something went wrong :(\n");
}

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
*/
