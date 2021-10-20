/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:15:14 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 18:53:17 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_control *control)
{
	int i;

	i = control->view.color;
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		exit_program(control);
	else if (keycode == PLUS_SIGN)
		control->view.precision *= 2.0;
	else if (keycode == MINUS_SIGN)
		control->view.precision /= 2.0;
	else if (keycode == KEY_C)
	{
		if (i >= 5 || i < 1)
			control->view.color = 1;
		else
			control->view.color += 1;
		printf("%d", i);
	}
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
