/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:43:12 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/16 12:12:01 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

/*for each y number the complete x row will be calculated.
The calculation works like follows:
In the while loop it will be iteratet until I hit the number 4 so i calculate Z.
Meanwhile in the while loop at first the real part will be calculated (C).
After that the imaginary part of C will be calculated.
In the end just paint every pixel from 0 black up to 255 white.*/

void	mandelbrot(t_fractol *fract)
{
	int			color;
	int			i;

	fract->my = 0;
	while (fract->my < HEIGHT)
	{
		fract->mx = 0;
		while (fract->mx < WIDTH)
		{
			i = mandelbrot_helper(fract);
			color = (i * 255) / MAX_ITER;
			mlx_put_pixel(fract->img, fract->mx, fract->my, color);
			fract->mx++;
		}
		fract->my++;
	}
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}

int	mandelbrot_helper(t_fractol *fract)
{
	int			i;
	double		x_new;

	i = 0;
	fract->x = 0.0;
	fract->y = 0.0;
	while (fract->x * fract->x + fract->y * fract->y
		<= 2 * 2 && i < MAX_ITER)
	{
		x_new = fract->x * fract->x - fract->y
			* fract->y + fract->mx * SCALE_FACTOR_X - 2.5;
		fract->y = 2 * fract->x * fract->y
			+ fract->my * SCALE_FACTOR_Y - 1.0;
		fract->x = x_new;
		i++;
	}
	return (i);
}
