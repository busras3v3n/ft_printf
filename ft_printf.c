/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:05:41 by busseven          #+#    #+#             */
/*   Updated: 2024/11/05 11:49:15 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

static int ft_handleformat(int i, const char *s, va_list *args)
{
    int c;
    c = i+1;
    int count;
    count = 0;

    if(s[c] == 'c')
        count += ft_case_char(va_args(*arg, char));
    else if(s[c] == 's')
    else if(s[c] == 'p')
    else if(s[c] == 'd')
    else if(s[c] == 'i')
    else if(s[c] == 'u')
    else if(s[c] == 'x')
    else if(s[c] == 'X')
    else if(s[c] == '%')
    return(count);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    va_start(args, s);
    int count;
    int i;

    i = 0;
    count = 0;
    while(s[i])
    {
        if(s[i] == '%')
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