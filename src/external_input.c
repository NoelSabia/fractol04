/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:12:06 by noel              #+#    #+#             */
/*   Updated: 2023/12/16 10:11:56 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./fractol.h"

void    press_esc(mlx_key_data_t keydata, void *params)
{
    t_fractol *fract;

    fract = (t_fractol *)params;
    if (keydata.key == MLX_KEY_ESCAPE)
    {
        freeing(fract);
        exit (0);
    }
}

void    mouse_scroll(double a, double b, void *params)
{
    t_fractol *fract;
    
    fract = (t_fractol *)params;
    a++;
    
}

void    resize_window(int width, int height, void *params)
{
    t_fractol *fract;

    fract = (t_fractol *)params;
    
}
