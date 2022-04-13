/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:19:05 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/13 11:37:24 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	int	len;

	if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
