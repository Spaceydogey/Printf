#include <stdio.h>
#include "ft_printf.h"
int main()
{
	char *str = "%%test [%p] ";
		
	printf("len : [%d] \n",ft_strlen(str) - 2);
	printf("printf len : [%d] \n",printf(str,str));
	printf("ft len : [%d] \n",ft_printf(str,str));
}
