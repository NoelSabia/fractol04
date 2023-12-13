/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:09:23 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/13 19:31:56 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("./fractol <mandelbrot/julia> <x for julia> <y for julia>\n");
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		mandelbrot();
	else if (ft_strncmp(argv[1], "julia", 6) == 0 && argc > 2)
		julia();
	else
		ft_printf("./fractol <mandelbrot/julia> <x for julia> <y for julia>\n");
}
