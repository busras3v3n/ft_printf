#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"
#include <limits.h>

int main()
{
	ft_printf("%-15.15d", (int)-2147483648);
}