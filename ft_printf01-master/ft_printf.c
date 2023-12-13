/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:41:15 by noel              #+#    #+#             */
/*   Updated: 2023/10/25 15:15:47 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdlib.h>

static void	check_which(char c, int *i, va_list args, int *ptr_len)
{
	if (c == 'p')
		show_pointeradress(va_arg(args, size_t), ptr_len);
	else if (c == 'd' || c == 'i')
		print_decimal_or_int(va_arg(args, int), ptr_len);
	else if (c == 'u')
		print_unsigned_int(va_arg(args, unsigned int), ptr_len);
	else if (c == 'x')
		print_hex_lower(va_arg(args, unsigned int), ptr_len);
	else if (c == 'X')
		print_hex_upper(va_arg(args, unsigned int), ptr_len);
	else if (c == '%')
	{
		(*ptr_len)++;
		if (write (1, "%", 1) == -1)
			(*ptr_len) = -1;
	}
	else if (c == 'c')
		print_one_char(va_arg(args, int), ptr_len);
	else if (c == 's')
		print_str(va_arg(args, char *), ptr_len);
	else
	{
		(*i)--;
		write (1, "%", 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		*ptr_len;

	va_start (args, str);
	len = 0;
	ptr_len = &len;
	i = 0;
	while (str[i] != 0 && len >= 0)
	{
		if (str[i] == '%')
		{
			i++;
			check_which(str[i], &i, args, ptr_len);
			i++;
		}
		else
			ft_putchar(str[i++], ptr_len);
		if (len == -1)
			return (-1);
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	ft_printf("%p\n", "");
// 	printf("%p\n", "");
// }