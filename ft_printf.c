/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:55 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/13 14:06:51 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_decimal(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex(va_arg(args, unsigned int));
	else if (format == '%')
		len += write(1, "%", 1);
	else if (format == '\0')
		;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_check;
	int		len;
	int		i;

	i = -1;
	len = 0;
	len_check = 0;
	va_start(args, str);
	while (str[++i])
	{
		len_check = len;
		if (str[i] == '%')
			len += ft_print_format(args, str[++i]);
		else
			len += ft_print_char(str[i]);
		if (len_check > len)
		{
			len = -1;
			break ;
		}
	}
	va_end(args);
	return (len);
}
