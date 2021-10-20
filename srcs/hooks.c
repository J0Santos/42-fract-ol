/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:15:14 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 18:33:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_control *control)
{
	if (keycode == ESC_KEY)
		exit_program(control);
	else if (keycode == PLUS_SIGN)
		control->view.precision *= 2.0;
	else if (keycode == MINUS_SIGN)
		control->view.precision /= 2.0;
	render_fractal(control);
	return(keycode);
}

int	mouse_hook(int	mousecode, int x, int y, t_control *control)
{
	(void)y;
	(void)x;
	if (mousecode == ZOOM_IN)
		control->view.zoom *= 1.05;
	else if (mousecode == ZOOM_OUT)
		control->view.zoom /= 1.05;
	render_fractal(control);
	return(mousecode);
}

int	red_cross(t_control *control)
{
	exit_program(control);
	return (0);
}
