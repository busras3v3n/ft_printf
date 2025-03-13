#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"

int main()
{
	printf("%-50.30x\n", 112);
	ft_printf("%-50.30x\n", 112);
}