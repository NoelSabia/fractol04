/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_or_int_nums.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:45:13 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/26 12:00:08 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	print_dec_or_int_helper1(int n, int *ptr_len)
{
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) == -1)
			return ((*ptr_len) = -1);
		return ((*ptr_len) += 11);
	}
	if (n == 0)
	{
		if (write (1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}

static int	print_decimal_or_int_helper2(int n, int *ptr_len)
{
	while (n < 0 && !(n == -2147483648))
	{
		n *= -1;
		if (write (1, "-", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	return (n);
}

int	print_decimal_or_int(int n, int *ptr_len)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(12);
	if (!temp)
		return ((*ptr_len) = -1);
	i = 0;
	print_dec_or_int_helper1(n, ptr_len);
	n = print_decimal_or_int_helper2(n, ptr_len);
	while (n > 0 && !(n == -2147483648))
	{
		temp[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
	{
		if (write (1, &temp[i], 1) == -1)
		{
			free (temp);
			return ((*ptr_len) = -1);
		}
		(*ptr_len)++;
	}
	free(temp);
	return (*ptr_len);
}
