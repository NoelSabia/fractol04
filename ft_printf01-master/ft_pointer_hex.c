/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:43:41 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/26 16:31:50 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	show_pointeradress_helper1(size_t ptr, int *ptr_len)
{
	if (ptr == 0)
	{
		if (write (1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}

static int	show_pointeradress_helper2(int *ptr_len)
{
	if (write (1, "0x", 2) == -1)
		return ((*ptr_len) = -1);
	return ((*ptr_len) += 2);
}

int	show_pointeradress(size_t ptr, int *ptr_len)
{
	char	*base;
	char	*placeholder;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (show_pointeradress_helper2(ptr_len) == -1
		|| show_pointeradress_helper1(ptr, ptr_len) == -1)
		return (*ptr_len);
	placeholder = (char *)malloc(16);
	if (!placeholder)
		return ((*ptr_len) = -1);
	while (ptr != 0)
	{
		placeholder[i++] = base[ptr % 16];
		ptr /= 16;
	}
	while (i--)
	{
		if (write (1, &placeholder[i], 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	free(placeholder);
	return (*ptr_len);
}
