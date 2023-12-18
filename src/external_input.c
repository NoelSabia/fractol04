/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:12:06 by noel              #+#    #+#             */
/*   Updated: 2023/12/18 15:35:02 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	press_esc(mlx_key_data_t keydata, void *params)
{
	t_fractol	*fract;

	fract = (t_fractol *)params;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		freeing(fract);
		exit (0);
	}
	else
		return ;
}

void	mouse_scroll(double a, double b, void *params)
{
	t_fractol	*fract;
	double		zoom_factor;

	fract = (t_fractol *)params;
	if (b > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	fract->zoom *= zoom_factor;
	fract->offsetx *= zoom_factor;
	fract->offsety *= zoom_factor;
	if (fract->fractal_type == 1)
		mandelbrot(fract);
	else if (fract->fractal_type == 2)
		julia(fract);
}

void	resize_window(int a, int b, void *params)
{
	t_fractol	*fract;
	double		ratio;
	double		new_ratio;

	fract = (t_fractol *)params;
	fract->width = a;
	fract->height = b;
	ratio = (double)fract->width / (double)fract->height;
	new_ratio = (double)a / (double)b;
	if (ratio < new_ratio)
	{
		fract->width = a;
		fract->height = a / ratio;
	}
	else
	{
		fract->width = b * ratio;
		fract->height = b;
	}
	mlx_resize_image(fract->img, fract->width, fract->height);
	if (fract->fractal_type == 1)
		mandelbrot(fract);
	else if (fract->fractal_type == 2)
		julia(fract);
}
