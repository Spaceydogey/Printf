#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main()
{
//	int	len;
	int	ftlen;
//	len = printf("%c", '0');
	ftlen = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
//	printf("\nprintf [%d]", len);
	printf("\nft_printf [%d]", ftlen);


}

