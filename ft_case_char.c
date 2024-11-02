/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:48:37 by busseven          #+#    #+#             */
/*   Updated: 2024/11/02 17:02:24 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include <stdarg.h>

int ft_case_char(va_list args)
{
    char c;
    c = va_arg(args, char);
    ft_putchar_fd(c, 1);
    return(1);
}