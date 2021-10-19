/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:43:55 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 00:00:25 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_control	*init_control_room(char *str)
{
	t_control	*control;
	t_img		*img;

	control = malloc(sizeof(t_control));
	if (!control)
		ft_error("Error allocating control\n");
	control->pixels = malloc(sizeof(t_pxl) * HEIGTH * WIDTH);
	control->mlx = mlx_init();
	control->win = mlx_new_window(control->mlx, WIDTH, HEIGTH, str);
	img = malloc(sizeof(t_img));
	if (!img)
		ft_error("Error allocating img\n");
	img->img = mlx_new_image(control->mlx, WIDTH, HEIGTH);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, 
		&img->endian);
	control->img = img;
	return (control);
}
