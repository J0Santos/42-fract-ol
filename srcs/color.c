/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:15:20 by josantos          #+#    #+#             */
/*   Updated: 2021/10/19 22:52:45 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int precision, int color)
{
	if(iteration >= precision)
		return (create_trgb(0, 0, 0, 0));
	else if (color == RED)
		return (create_trgb(0, 255, iteration * 20.5, 0));
	else if(color == GREEN)
		return (create_trgb(0, 0, 255, iteration * 5.5));
	else if (color == BLUE)
		return (create_trgb(0, iteration * 5.5, 0, 255));
	return (create_trgb(0, iteration * 5.5, iteration * 5.5, iteration * 5.5));
}
