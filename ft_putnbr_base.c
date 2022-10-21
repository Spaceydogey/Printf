/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:57:40 by hdelmas           #+#    #+#             */
/*   Updated: 2022/10/21 17:59:43 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_condititon(long int base_len, char *base)
{	
	long int	i;
	long int	j;

	if (base_len <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == 45 || base[i] == 43 || base[i] < 33)
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_fd(unsigned long int nbr, char *base, int fd)
{
	size_t	base_len;
	int		nbr_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (ft_condititon(base_len, base) == 0)
		return (-1);
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
