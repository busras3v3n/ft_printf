/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:05:41 by busseven          #+#    #+#             */
/*   Updated: 2024/11/06 09:52:05 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"

static int ft_handleformat(int i, const char *s, va_list *args)
{
    int c;
    int count;

    c = i+1;
    count = 0;
    if (s[c] == 'c' || s[c] == '%')
        count += ft_print_char(va_arg(*args, int));
    else if (s[c] == 's')
        count += ft_print_str(va_arg(*args, char *));
    else if (s[c] == 'i' || s[c] == 'd')
        count += ft_print_nbr(va_arg(*args, int));
    else if (s[c] == 'u')
        count += ft_print_nbr(va_arg(*args, unsigned int));
        else if (s[c] == 'x' || s[c] == 'X')
        count += ft_print_hex(va_arg(*args, int), s[c]);
    return (count);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    va_start(args, s);
    int count;
    int i;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            count += ft_handleformat(i, s, &args);
            i = i + 2;
        }
        else
        {
            ft_putchar_fd(s[i], 1);
            count++;
            i++;
        }
    }
    va_end(args);
    return (count);
}