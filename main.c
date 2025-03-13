#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"

int main()
{
	printf("%0-*.*x", 25, 3, 112);
	ft_printf("%0-*.*x", 25, 3, 112);
}