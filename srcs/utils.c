/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:29:22 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 19:03:24 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_loop(t_control *control)
{
	mlx_key_hook(control->win, key_hook, control);
	mlx_mouse_hook(control->win, mouse_hook, control);
	mlx_hook(control->win, 17, 1L << 17, red_cross, control);
	mlx_loop(control->mlx);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
