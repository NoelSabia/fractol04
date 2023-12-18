/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/18 19:27:03 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>
# include <math.h>
# include "./Libft00/libft.h"
# include "./ft_printf01-master/ft_printf.h"
# include "MLX42-master/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	int				fractal_type;
	int				mx;
	int				my;
	double			realpart;
	double			imagpart;
	double			copyimag;
	double			copyreal;
	double			scale;
	double			scalej;
	double			sqra;
	double			sqrb;
	double			sqr_diff;
	double			product;
	double			arg1;
	double			arg2;
	double			jx;
	double			jy;
	double			sqraa;
	double			sqrbb;
	double			sqraa2;
	double			sqrbb2;
	double			zoom;
	double			width;
	double			height;
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_fractol;

/*Dimensions*/
# define WIDTH 2560
# define HEIGHT 1315
# define MAX_ITER 100

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