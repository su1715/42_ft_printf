/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:30:56 by sujpark           #+#    #+#             */
/*   Updated: 2022/02/21 17:51:19 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr(unsigned long long num, int *len)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16, len);
		ft_print_ptr(num % 16, len);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
		*len++;
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	len;

	len += write(1, "0x", 2);
	ft_print_ptr(ptr, len);
	return (len);
}
