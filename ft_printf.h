/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:24:27 by sujpark           #+#    #+#             */
/*   Updated: 2022/04/13 13:50:55 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_decimal(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex_upper(size_t num);
int	ft_print_hex(size_t num);
int	ft_print_pointer(void *ptr);

#endif
