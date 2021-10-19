/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:28:18 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 00:20:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	t_control	*control;

	if (argc < 2)
		ft_error("Minimum params must be:\n\t./fractol <fractal_name> [x][y]\n");
	fractal = init_fractal(argv[1]);
	control = init_control_room(argv[1]);
	control->fractal = fractal;
	init_view(control);
	render_fractal(control);
	mlx_loop(control->mlx);
	printf("Execution successful\n");
	exit(EXIT_SUCCESS);
}
