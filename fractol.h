/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/14 19:13:36 by nsabia           ###   ########.fr       */
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
	double			x;
	double			y;
	int				mx;
	int				my;
	int				jx;
	int				jy;
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_fractol;

/*Dimensions*/
# define WIDTH 2560
# define HEIGHT 1315
# define MAX_ITER 70
# define SCALE_FACTOR_X (3.5 / WIDTH)
# define SCALE_FACTOR_Y (2.0 / HEIGHT)
#define ZOOM 4.0
#define OFFSETX 0.0
#define OFFSETY 0.0

/*C-Files*/
void	mandelbrot(t_fractol *fract);
int		mandelbrot_helper(t_fractol *fract);
void	julia(int jx, int jy);
void	choose_fractal(int argc, char **argv, t_fractol *fract);

#endif