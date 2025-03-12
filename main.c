#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"

int main()
{
	printf("%20.8x\n", 112);
	ft_printf("%20.8x\n", 112);
}