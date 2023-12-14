/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:23 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/14 12:42:26 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	julia_checker(char *str2, char *str3, t_fractol *fract)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	while (str2[i] != '\0' && str3[i] != '\0')
	{
		if (ft_isdigit(str2[i]) == 0 || ft_isdigit(str3[i]) == 0)
		{
			ft_printf("Please just enter numbers as 2 and 3 parameter.\n");
			exit(0);
		}
		i++;
		y++;
	}
	x = ft_atoi(str2);
	y = ft_atoi(str3);
	fract->jx = x;
	fract->jy = y;
	julia(fract->jx, fract->jy);
}

void	initialize_window(void)
{
	
}

void	choose_fractal(int argc, char **argv, t_fractol *fract)
{
	if (argc < 2)
	{
		ft_printf("Please enter a fractal name.\n");
		return ;
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		mandelbrot();
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (!argv[2] || !argv[3])
			julia_checker("5", "5", fract);
		else
			julia_checker(argv[2], argv[3], fract);
	}
	else
	{
		ft_printf("Please enter a valid fractal name.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*fract;

	fract = malloc(sizeof(t_fractol));
	choose_fractal(argc, argv, fract);
	initialize_window();
	fract->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	mlx_loop(fract->mlx);
	free (fract);
}
