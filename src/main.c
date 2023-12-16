/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:23 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/16 12:11:28 by nsabia           ###   ########.fr       */
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
	double			x;
	double			y;

	i = 0;
	x = 0;
	y = 0;
	while (str2[i] != '\0' && str3[i] != '\0')
	{
		if (ft_isalpha(str2[i]) == 1 || ft_isalpha(str3[i]) == 1)
		{
			ft_printf("Please just enter numbers as 2 and 3 parameter.\n");
			exit(0);
		}
		i++;
	}
	x = ft_atof(str2);
	y = ft_atof(str3);
	fract->jx = x;
	fract->jy = y;
	fract->fractal_type = 2;
	julia(fract);
}

void	choose_fractal(int argc, char **argv, t_fractol *fract)
{
	if (argc < 2 || !((ft_strncmp(argv[1], "mandelbrot", 11) == 0)
			&& !(ft_strncmp(argv[1], "julia", 6) == 0)))
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
	fract->zoom = 1.0;
	fract->offsetx = 0.0;
	fract->offsety = 0.0;
	fract->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	choose_fractal(argc, argv, fract);
	mlx_key_hook(fract->mlx, press_esc, fract);
	mlx_scroll_hook(fract->mlx, mouse_scroll, fract);
	// mlx_resize_hook(mlx, resize_window, fract);
	mlx_loop(fract->mlx);
	freeing (fract);
	return (0);
}
