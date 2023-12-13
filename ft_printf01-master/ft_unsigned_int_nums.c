/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_nums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:29:36 by noel              #+#    #+#             */
/*   Updated: 2023/10/26 11:48:16 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	print_unsigned_int_helper(unsigned int u, int *ptr_len)
{
	if (u == 0)
	{
		if (write(1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}

static char	*print_unsigned_int_helper2(unsigned int u, char *temp)
{
	int	i;

	i = 0;
	while (u > 0)
	{
		temp[i] = (u % 10) + '0';
		i++;
		u /= 10;
	}
	temp[i] = '\0';
	return (temp);
}

static	int	print_unsigned_int_helper3(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int	print_unsigned_int(unsigned int u, int *ptr_len)
{
	char	*temp;
	int		i;

	if (u < 0)
		u -= 4294967295;
	if (print_unsigned_int_helper(u, ptr_len) == -1)
		return ((*ptr_len) = -1);
	if (u == 0)
		return (*ptr_len);
	temp = (char *)malloc(12);
	if (!temp)
		return ((*ptr_len) = -1);
	temp = print_unsigned_int_helper2(u, temp);
	i = print_unsigned_int_helper3(temp);
	while (i--)
	{
		if (write(1, &temp[i], 1) == -1)
		{
			free(temp);
			return ((*ptr_len) = -1);
		}
		(*ptr_len)++;
	}
	free(temp);
	return (*ptr_len);
}
