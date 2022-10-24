/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:58:18 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/24 15:13:24 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(va_list ap, int fd)
{
	int	out_len;

	out_len = 0;
	out_len = ft_putstr_fd("0x", fd);
	out_len += ft_putnbr_base_fd(va_arg(ap, unsigned long int),
			"0123456789abcdef", fd);
	return (out_len);
}

static int	ft_conv(char type, va_list ap, int fd)
{
	int	out_len;

	out_len = 0;
	if (type == 'c')
		out_len = ft_putchar_fd(va_arg(ap, int), fd);
	else if (type == 's')
		out_len = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (type == 'd' || type == 'i')
		out_len = ft_putnbr_fd(va_arg(ap, int), fd);
	else if (type == 'p')
		out_len = ft_print_ptr(ap, fd);
	else if (type == 'x')
		out_len = ft_putnbr_base_fd(va_arg(ap, unsigned int),
				"0123456789abcdef", fd);
	else if (type == 'X')
		out_len = ft_putnbr_base_fd(va_arg(ap, unsigned int),
				"0123456789ABCDEF", fd);
	else if (type == 'u')
		out_len = ft_putnbr_base_fd(va_arg(ap, unsigned int),
				"0123456789", fd);
	else if (type == '%')
		out_len = ft_putchar_fd('%', fd);
	return (out_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, format);
	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (print_len);
			print_len += ft_conv(*format, ap, 1);
			format++;
		}
		else
		{
			if (*format == '\0')
				return (print_len);
			ft_putchar_fd(*format, 1);
			print_len++;
			format++;
		}
	}
	va_end(ap);
	return (print_len);
}
