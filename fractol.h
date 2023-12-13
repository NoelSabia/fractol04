/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/13 19:18:22 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include "./Libft00/libft.h"
# include "./ft_printf01-master/ft_printf.h"
# include "MLX42-master/include/MLX42/MLX42.h"

typedef struct s_fractol
{
    int             mx;
    int             my;
    int             jx;
    int             jy;
    mlx_t*          mlx;
}				t_fractol;

/*Dimensions*/
# define WIDTH 2560
# define HEIGHT 1315
# define MAX_ITER 60

/*C-Files*/
void	mandelbrot(void);
void	julia(void);

#endif