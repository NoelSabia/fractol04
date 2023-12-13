/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:59:46 by noel              #+#    #+#             */
/*   Updated: 2023/10/26 10:50:10 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_putchar(char c, int *ptr_len);
int		show_pointeradress(size_t m, int *ptr_len);
int		print_decimal_or_int(int n, int *ptr_len);
int		print_unsigned_int(unsigned int u, int *ptr_len);
int		print_hex_lower(unsigned int num, int *ptr_len);
int		print_hex_upper(unsigned int num, int *ptr_len);
int		print_one_char(int c, int *ptr_len);
int		print_str(char *str, int *ptr_len);
int		ft_printf(const char *str, ...);

#endif
