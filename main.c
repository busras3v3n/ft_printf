#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"

int main()
{
	printf("%d" , ft_printf("%-1d", 10));
}