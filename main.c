#include "./libft/libft.h"
#include "libftprintf.h"
#include <unistd.h>

int main()
{
    int a = 199;
    char *b = "busra";
    ft_printf("%i bundan sonra bir string %s", a, b);
}