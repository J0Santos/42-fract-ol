/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:29:22 by josantos          #+#    #+#             */
/*   Updated: 2021/10/19 23:52:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dest;

    dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int *)dest = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
