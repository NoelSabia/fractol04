/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:23 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/15 19:42:31 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	freeing(t_fractol *fract)
{
	free(fract->mlx);
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

	fract = malloc(sizeof(t_fractol));
	img = NULL;
	fract->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	choose_fractal(argc, argv, fract);
	mlx_loop(fract->mlx);
	freeing (fract);
}
