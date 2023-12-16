/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:12:06 by noel              #+#    #+#             */
/*   Updated: 2023/12/16 11:55:18 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./fractol.h"

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

void	resize_window(int width, int height, void *params)
{
	t_fractol	*fract;

	fract = (t_fractol *)params;
}
