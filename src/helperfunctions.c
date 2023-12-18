/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:54:57 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/18 18:14:51 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../fractol.h"
// #include <ctype.h>

// double	ft_atof(const char *s)
// {
//   	double	a;
//   	int 	e;
//   	int		c;
// 	int		sign;
//     int		i;

// 	a = 0.0;
// 	e = 0;
// 	sign = 1;
// 	i = 0;
// 	while ((c = *s++) != '\0' && isdigit(c))
// 		a = a * 10.0 + (c - '0');
// 	if (c == '.')
// 	{
// 		while ((c = *s++) != '\0' && isdigit(c))
// 		{
// 			a = a * 10.0 + (c - '0');
// 			e -= 1;
// 		}
// 	}
// 	if (c == 'e' || c == 'E')
// 	{
// 		c = *s++;
// 		if (c == '+')
// 			c = *s++;
// 		else if (c == '-')
// 		{
// 			c = *s++;
// 			sign = -1;
// 		}
// 		while (isdigit(c))
// 		{
// 			i = i * 10 + (c - '0');
// 			c = *s++;
// 		}
// 		e += i * sign;
// 	}
// 	while (e > 0)
// 	{
// 		a *= 10.0;
// 		e--;
// 	}
// 	while (e < 0)
// 	{
// 		a *= 0.1;
// 		e++;
// 	}
// 	return (a);
// }

// int main()
// {
// 	char *str = "0.123";
// 	double a = ft_atof(str);
// 	printf("%f\n", a);
// 	return (0);
// }
// //rewrite