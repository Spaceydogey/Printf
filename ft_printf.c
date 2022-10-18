/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:55 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/18 11:32:56 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv(char type, va_list ap, int fd, int out_len)
{
	if (type == 'c')
		out_len = ft_putchar_fd(va_arg(ap, char), fd, out_len);
	else if (type == 's')
		out_len = ft_putstr_fd(va_arg(ap,char *), fd, out_len);
	else if (type == 'd' || type == 'i')
		out_len = ft_putnbr_base(va_arg(ap, int), "0123456789", out_len);
	else if (type == 'p')
		out_len = ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", out_len);
	else if (type == 'x')
		out_len = ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", out_len);
	else if (type == 'X')
		out_len = ft_putnbr_base(to_print, "0123456789ABCDEFG", out_len);
	else if (type == 'u')
		 out_len = ft_putnbr_base(to_print, "0123456789", out_len);
	else if (type == '%')
		out_len = ft_putchar_fd('%', fd, out_len);
	return (out_len);
}

int	ft_printf(const char *format ...)
{
	va_list	ap;

	va_start(ap, format);


}