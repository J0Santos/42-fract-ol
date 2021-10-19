/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:44:48 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 00:09:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_view(t_control *control)
{
	control->view.x_max = WIDTH / 2;
	control->view.y_max = HEIGTH / 2;
	control->view.x_min = -1 * (WIDTH / 2);
	control->view.y_min = -1 * (HEIGTH / 2);
	control->view.zoom = ZOOM;
	control->view.precision = PRECISION;
	control->width = WIDTH;
	control->heigth = HEIGTH;
	control->view.mouse = (t_complex){-0.835, -0.232};
	control->view.color = 5;
}
