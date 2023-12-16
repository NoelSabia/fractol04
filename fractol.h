/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/16 12:10:16 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>
# include "./Libft00/libft.h"
# include "./ft_printf01-master/ft_printf.h"
# include "MLX42-master/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	int				fractal_type;
	double			real;
	double			imag;
	double			x;
	double			y;
	int				mx;
	int				my;
	double			jx;
	double			jy;
	double			zoom;
	double			offsetx;
	double			offsety;
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_fractol;

/*Dimensions*/
# define WIDTH 2560
# define HEIGHT 1315
# define MAX_ITER 100
# define SCALE_FACTOR_X (3.5 / WIDTH)
# define SCALE_FACTOR_Y (2.0 / HEIGHT)

#ifndef C_RE
# define C_RE -0.8
#endif

#ifndef C_IM
# define C_IM -0.156
#endif

/*C-Files*/
void	mandelbrot(t_fractol *fract);
int		mandelbrot_helper(t_fractol *fract);
void	julia(t_fractol *fract);
int		julia_helper(t_fractol *fract);
void	choose_fractal(int argc, char **argv, t_fractol *fract);
void	freeing(t_fractol *fract);
double	ft_atof(const char *s);
void	press_esc(mlx_key_data_t keydata, void *params);
void	mouse_scroll(double a, double b, void *params);
void	resize_window(int width, int height, void *params);

#endif