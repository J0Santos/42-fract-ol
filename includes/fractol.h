/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:14:00 by josantos          #+#    #+#             */
/*   Updated: 2021/10/21 15:57:59 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ESC_KEY 53
# define ZOOM_IN  5
# define ZOOM_OUT  4
# define PLUS_SIGN 69
# define MINUS_SIGN 78
# define KEY_C 8

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGTH
#  define HEIGTH 1080
# endif

# ifndef PRECISION
#  define PRECISION 500
# endif

# define ZOOM_DEF 256

# define RED 1
# define GREEN 2
# define BLUE 3
# define B_W 4

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "math.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_complex
{
	float	re;
	float	im;
}	t_complex;

typedef struct s_pixel
{
	int			iter;
	t_complex	pixel;
}	t_pxl;

typedef struct s_view
{
	float		x_min;
	float		x_max;
	float		y_min;
	float		y_max;
	float		zoom;
	int			precision;
	t_complex	mouse;
	int			color;
}	t_view;

typedef t_pxl	(*t_fn_fractal)(int x, int y, t_view *view);

typedef struct s_fractal
{
	char			*fractal;
	t_fn_fractal	fn_fractal;
}	t_fractal;

typedef struct s_control_room
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_fractal	*fractal;
	t_view		view;
	t_pxl		*pixels;
	int			width;
	int			heigth;
}	t_control;

t_fractal	*init_fractal(char *str);
t_control	*init_control_room(char *str);
void		init_view(t_control *control, char **argv);
void		render_fractal(t_control *control);
t_pxl		mandelbrot_set(int x, int y, t_view *view);
t_pxl		julia_set(int x, int y, t_view *view);
t_complex	get_complex(int x, int y, t_view *view);
void		pixels_to_image(t_control *control);
int			get_color(int iteration, int precision, int color);
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		init_loop(t_control *control);
int			key_hook(int key_code, t_control *control);
int			mouse_hook(int mousecode, int x, int y, t_control *control);
int			red_cross(t_control *control);
void		exit_program(t_control *control);

#endif
