/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:05:41 by busseven          #+#    #+#             */
/*   Updated: 2024/11/05 12:02:15 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

static int ft_handleformat(int i, const char *s, va_list *args)
{
    int c;
    int count;

    c = i+1;
    count = 0;
    if (s[c] == 'c' || s[c] == '%')
        count += ft_print_char(va_args(*args, char));
    else if (s[c] == 's')
        count += ft_print_str(va_args(*args, char *));
    else if (s[c] == 'p')
        count += ft_print_void(va_args(*args, void *));
    else if( s[c] == 'd' || s[c] == 'i')
        count += ft_print_nbr(va_args(*args, int));
    else if (s[c] == 'u')
        count += ft_print_uint(va_args(*args, int));
    else if (s[c] == 'x' || s[c] == 'X')
        count += ft_print_hex(va_args(*args, int));
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
            count += ft_handleformat(s, i, args);
        else
        {
            ft_putchar_fd(s[i], 1);
            count++;
        }
        i++;
    }
    ft_putchar_fd('\n', 1);
    va_end(args);
    return (count);
}