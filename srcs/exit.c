/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:21:36 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 18:54:47 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_program(t_control *control)
{
	mlx_destroy_window(control->mlx, control->win);
	free(control->fractal);
	free(control->pixels);
	free(control);
	printf("Success!!\n");
	exit(EXIT_SUCCESS);
}
