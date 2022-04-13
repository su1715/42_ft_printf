/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:30:56 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/13 11:59:35 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(size_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_hex_upper(num / 16);
	num %= 16;
	len += ft_print_char("0123456789ABCDEF"[num]);
	return (len);
}

int	ft_print_hex(size_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_hex(num / 16);
	num %= 16;
	len += ft_print_char("0123456789abcdef"[num]);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	size_t	num;
	int		len;

	len = 0;
	num = (size_t)ptr;
	len += write(1, "0x", 2);
	len += ft_print_hex(num);
	return (len);
}
