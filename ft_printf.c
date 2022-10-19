/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:58:18 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/19 10:00:47 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:55 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/19 09:58:09 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv(char type, va_list ap, int fd)
{
	int	out_len;

	out_len = 0;
	if (type == 'c')
		out_len = ft_putchar_fd(va_arg(ap, int), fd);
	else if (type == 's')
		out_len = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (type == 'd' || type == 'i')
		out_len = ft_putnbr_base(va_arg(ap, int), "0123456789", 0);
	else if (type == 'p')
	{
		out_len = ft_putstr_fd("0x", 1);
		out_len += ft_putnbr_base(va_arg(ap, unsigned long int),
				"0123456789abcdef", 0);
	}
	else if (type == 'x')
		out_len = ft_putnbr_base(va_arg(ap, unsigned long int),
				"0123456789abcdef", 0);
	else if (type == 'X')
		out_len = ft_putnbr_base(va_arg(ap, unsigned long int),
				"0123456789ABCDEFG", 0);
	else if (type == 'u')
		 out_len = ft_putnbr_base(va_arg(ap, unsigned int),
				 "0123456789", 0);
	else if (type == '%')
		out_len = ft_putchar_fd('%', fd);
	return (out_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	print_len;

	va_start(ap, format);
	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_len += ft_conv(*format, ap, 1);
			format++;
		}
		ft_putchar_fd(*format, 1);
		print_len++;
		format++;
	}
	return (print_len);
}
