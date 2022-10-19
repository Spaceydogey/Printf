#include "ft_printf.h"

static int	ft_condititon(int base_len, char *base)
{	
	int	i;
	int	j;

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

static int	ft_putnbrpos(long long int nb, int base_len, char *base, int nbr_len)
{
	if (nb < base_len)
		{
			write(1, &base[nb], 1);
			nbr_len++;
		}
	else
	{
		nbr_len += ft_putnbr_base(nb / base_len, base, nbr_len);
		nbr_len += ft_putnbr_base(nb % base_len, base, nbr_len);
	}
	return (nbr_len);
}

static int	ft_putnbrneg(long long int nb, int base_len, char *base, int nbr_len)
{
	if (nb > -base_len)
	{
		write(1, "-", 1);
		write(1, &base[-nb], 1);
		nbr_len += 2;
	}
	else
	{
		nbr_len += ft_putnbr_base(nb / base_len, base,  nbr_len);
		nbr_len += ft_putnbr_base(-nb % base_len, base,  nbr_len);
	}
	return (nbr_len);
}

int	ft_putnbr_base(long long int nbr, char *base, int nbr_len)
{
	size_t	base_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (ft_condititon(base_len, base) == 0)
		return (-1);
	if (nbr < 0)
		nbr_len += ft_putnbrneg(nbr, base_len, base, nbr_len);
	else
		nbr_len += ft_putnbrpos(nbr, base_len, base, nbr_len);
	return (nbr_len);
}
