#include <stdio.h>
#include "ft_printf.h"
#include "./bonus/ft_printf_bonus.h"

int main()
{
	printf("%+05.8i\n", -112);
	ft_printf("%+05.8i\n", -112);
}