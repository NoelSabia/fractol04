/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:43:12 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/14 19:08:27 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

/*for each y number the complete x row will be calculated.
The calculation works like follows:
In the while loop it will be iteratet until I hit the number 4 so i calculate Z
Meanwhile in the while loop at first the real part will be calculated (C)
After that the imaginary part of C will be calculated*/

void	mandelbrot(t_fractol *fract)
{
	int			color;
	int			i;
	double		x_new;

	fract->my = 0;
	while (fract->my < HEIGHT)
	{
		fract->mx = 0;
		while (fract->mx < WIDTH)
		{
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
			if (i == MAX_ITER)
				color = 0x000000;
			else
				color = (i * 255) / MAX_ITER;
			mlx_put_pixel(fract->img, fract->mx, fract->my, color);
			fract->mx++;
		}
		fract->my++;
	}
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}
