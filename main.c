#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"
#include <limits.h>

int main()
{
	printf("%d" , ft_printf("% s", "h"));
}