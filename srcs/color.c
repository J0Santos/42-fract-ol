/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:15:20 by josantos          #+#    #+#             */
/*   Updated: 2021/10/20 16:05:32 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int precision, int color)
{
	if(iteration >= precision)
		return (create_trgb(0, 0, 0, 0));
	else if (color == RED)
		return (create_trgb(0, 20.0 * iteration, iteration * 5.5, 
			iteration * 5.5));
	else if(color == GREEN)
		return (create_trgb(0, 0, 20.5 * iteration, 0));
	else if (color == BLUE)
		return (create_trgb(0, 5.5 * iteration, 5.5 * iteration, 
			20.5 * iteration));
	else if (color == B_W)
		return (create_trgb(0, iteration * 5.5, iteration * 5.5, 
			iteration * 5.5));
	return (create_trgb(0, iteration * 5.5, iteration * 20.5, 
		10.5 * iteration));

}
