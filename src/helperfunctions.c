/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:54:57 by nsabia            #+#    #+#             */
/*   Updated: 2023/12/19 15:00:04 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_process_decimal_part(const char *str)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	while (ft_isdigit(*str) == 1)
	{
		result += (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (result);
}

double	ft_strtod(const char *str, char **endptr)
{
	int		sign;
	double	result;

	sign = 1;
	result = 0.0;
	while (isspace(*str) == 1)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result += ft_process_decimal_part(str);
	}
	return (sign * result);
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_no_num(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}
