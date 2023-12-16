/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:44:02 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/15 12:15:31 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
/*This functions the same as mandelbrot does.
The only diference is what you put in there. 
The real number could be: 0.285, -0.7269
The imaginary number could be: 0.01, 0.1889*/

void	julia(t_fractol *fract)
{
	int	color;
	int	i;

	fract->my = 0;
	while (fract->my < HEIGHT)
	{
		fract->mx = 0;
		while (fract->mx < WIDTH)
		{
			i = julia_helper(fract);
			color = (i * 255) / MAX_ITER;
			mlx_put_pixel(fract->img, fract->mx, fract->my, color);
			fract->mx++;
		}
		fract->my++;
	}
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}

int	julia_helper(t_fractol *fract)
{
	int			i;
	double		x_new;

	i = 0;
	if (!fract->jx)
		fract->jx = C_RE;
	if (!fract->jy)
		fract->jy = C_IM;
	fract->x = fract->mx * SCALE_FACTOR_X - 2.5;
	fract->y = fract->my * SCALE_FACTOR_Y - 1.0;
	while (fract->x * fract->x + fract->y * fract->y
		<= 2 * 2 && i < MAX_ITER)
	{
		x_new = fract->x * fract->x - fract->y
			* fract->y + fract->jx;
		fract->y = 2 * fract->x * fract->y
			+ fract->jy;
		fract->x = x_new;
		i++;
	}
	return (i);
}
