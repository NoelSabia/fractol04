/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:43:12 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/18 17:36:20 by nsabia           ###   ########.fr       */
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

	fract->scale = 5;
	fract->my = 0;
	fract->fractal_type = 1;
	while (fract->my < fract->height)
	{
		fract->mx = 0;
		while (fract->mx < fract->width)
		{
			i = mandelbrot_helper(fract);
			color = (i * 255 / MAX_ITER);
			mlx_put_pixel(fract->img, fract->mx, fract->my, color);
			fract->mx++;
		}
		fract->my++;
	}
}

int	mandelbrot_helper(t_fractol *fract)
{
	int		i;

	i = 0;
	fract->realpart = (fract->mx / fract->width - 0.6) * fract->scale;
	fract->imagpart = (fract->my / (fract->height
				/ (fract->height / fract->width)) - 0.3) * fract->scale;
	fract->copyreal = fract->realpart;
	fract->copyimag = fract->imagpart;
	while (i < MAX_ITER)
	{
		fract->sqra = fract->realpart * fract->realpart;
		fract->sqrb = fract->imagpart * fract->imagpart;
		fract->sqr_diff = fract->sqra - fract->sqrb;
		fract->product = 2 * fract->realpart * fract->imagpart;
		fract->realpart = fract->sqr_diff + fract->copyreal;
		fract->imagpart = fract->product + fract->copyimag;
		if (fract->sqra + fract->sqrb > 3)
			break ;
		i++;
	}
	return (i);
}
