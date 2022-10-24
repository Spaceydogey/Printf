/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:57:40 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/24 07:51:20 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(unsigned long int nbr, char *base, int fd)
{
	unsigned long int	base_len;
	int					nbr_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (nbr < base_len)
		nbr_len += ft_putchar_fd(base[nbr], fd);
	else
	{
		nbr_len += ft_putnbr_base_fd(nbr / base_len, base, fd);
		nbr_len += ft_putnbr_base_fd(nbr % base_len, base, fd);
	}
	return (nbr_len);
}

int	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;
	int		sign;
	int		nbr_len;

	nbr_len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nbr_len += ft_putchar_fd('-', fd);
	}
	nbr = ((long int)n * sign);
	if (nbr <= 9)
		nbr_len += ft_putchar_fd(nbr + 48, fd);
	else
	{
		nbr_len += ft_putnbr_fd(nbr / 10, fd);
		nbr_len += ft_putnbr_fd(nbr % 10, fd);
	}
	return (nbr_len);
}
