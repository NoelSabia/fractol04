/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:44:02 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/19 14:17:04 by nsabia           ###   ########.fr       */
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
	while (fract->my < fract->height)
	{
		fract->mx = 0;
		while (fract->mx < fract->width)
		{
			i = julia_helper(fract);
			color = (i * 255 / MAX_ITER);
			mlx_put_pixel(fract->img, fract->mx, fract->my, color);
			fract->mx++;
		}
		fract->my++;
	}
}

int	julia_helper(t_fractol *fract)
{
	int		i;

	fract->realpart = (fract->mx / fract->width - 0.6) * fract->scalej;
	fract->imagpart = (fract->my / (fract->height
				/ (fract->height / fract->width)) - 0.3) * fract->scalej;
	i = 0;
	while (i < MAX_ITER)
	{
		fract->sqraa = fract->realpart * fract->realpart;
		fract->sqrbb = fract->imagpart * fract->imagpart;
		fract->sqraa2 = fract->sqraa - fract->sqrbb;
		fract->sqrbb2 = 2 * fract->realpart * fract->imagpart;
		fract->realpart = fract->sqraa2 + fract->arg1;
		fract->imagpart = fract->sqrbb2 + fract->arg2;
		if (fract->sqraa + fract->sqrbb > 4)
			break ;
		i++;
	}
	return (i);
}
