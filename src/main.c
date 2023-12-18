/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:23 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/18 18:19:11 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	freeing(t_fractol *fract)
{
	free(fract->mlx);
	free (fract->img);
	free(fract);
}

void	julia_checker(char *str2, char *str3, t_fractol *fract)
{
	int				i;
	double			arg1;
	double			arg2;

	i = 0;
	arg1 = 0;
	arg2 = 0;
	while (str2[i] != '\0' && str3[i] != '\0')
	{
		if (ft_isalpha(str2[i]) == 1 || ft_isalpha(str3[i]) == 1)
		{
			ft_printf("Please just enter numbers as 2 and 3 parameter.\n");
			exit(0);
		}
		i++;
	}
	arg1 = strtod(str2, NULL);
	arg2 = strtod(str3, NULL);
	fract->arg1 = arg1;
	fract->arg2 = arg2;
	fract->jx = fract->width;
	fract->jy = fract->height;
	fract->fractal_type = 2;
	julia(fract);
}

void	choose_fractal(int argc, char **argv, t_fractol *fract)
{
	if (argc < 2 || (!(ft_strncmp(argv[1], "mandelbrot", 11) == 0)
			&& (!(ft_strncmp(argv[1], "julia", 6) == 0))))
	{
		ft_printf("Invalid.\n 1. mandelbrot\n 2. julia\n");
		freeing(fract);
		exit(0);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		mandelbrot(fract);
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc == 2)
			julia_checker("-0.8", "0.156", fract);
		else if (argc == 3)
			julia_checker(argv[2], "0.156", fract);
		else if (argc == 4)
			julia_checker(argv[2], argv[3], fract);
		else
		{
			ft_printf("Too many arguments or wrong input.\n");
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*fract;
	mlx_image_t	*img;
	mlx_t		*mlx;

	fract = malloc(sizeof(t_fractol));
	img = NULL;
	mlx = NULL;
	fract->width = 1920;
	fract->height = 1080;
	fract->zoom = 0.0;
	fract->offsetx = 0.0;
	fract->offsety = 0.0;
	fract->mlx = mlx_init(fract->width, fract->height, "fractol", true);
	fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
	choose_fractal(argc, argv, fract);
	mlx_resize_hook(fract->mlx, resize_window, fract);
	mlx_key_hook(fract->mlx, press_esc, fract);
	mlx_scroll_hook(fract->mlx, mouse_scroll, fract);
	mlx_loop(fract->mlx);
	mlx_terminate(fract->mlx);
	freeing (fract);
	return (0);
}
