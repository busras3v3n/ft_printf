/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:15:44 by busseven          #+#    #+#             */
/*   Updated: 2024/11/02 17:06:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include <stdarg.h>

static int ft_handleformat(char c, va_list args)
{
    int bytes;
    bytes = 0;
    if(c == 'c')
        bytes += ft_case_char(args);
    return(bytes);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    va_start(args, s);
    int i;
    int ret;

    i = 0;
    ret = 0;
    while(s[i])
    {
        if(s[i] == '%')
        {
            if(!ft_strchr("cspdiuxX%", s[i + 1]))
                return(-1);
            else
                ret = ret + ft_handleformat(s[i + 1], args);
        }
        else
        {
            write(1, &s[i], 1);
            ret++;
        }
        i++;
    }
    va_end(args);
    return(ret);
}
