#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"
#include <limits.h>

int main()
{
	printf("%d" , ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}