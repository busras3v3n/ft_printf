/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:59:47 by busseven          #+#    #+#             */
/*   Updated: 2025/03/17 13:24:38 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_strlen(t_flags *flags, char *str)
{
	if(!str)
		return(6);
	else if(flags->prec_stat && flags->precision < (int)ft_strlen(str))
		return(flags->precision);
	else
		return(ft_strlen(str));
}

void	check_arg_len(t_flags *flags, va_list *args)
{
	va_list args_copy;

	va_copy(args_copy, *args);
	if(flags->type == 's')
		flags->len = get_strlen(flags, va_arg(args_copy, char *));
	else if(flags->type == 'i' || flags->type == 'd')
		flags->len = get_intlen_and_sign(flags, va_arg(args_copy, int));
	else if(flags->type == 'u')
		flags->len = get_uintlen(flags, va_arg(args_copy, unsigned int));
	else if(flags->type == 'c')
		flags->len = 1;
	else if(flags->type == 'x' || flags->type == 'X')
		flags->len = get_hexlen_and_ifzero(flags, va_arg(args_copy, int));
	else if(flags->type == 'p')
		flags->len = get_ptrlen(va_arg(args_copy, void *));
	va_end(args_copy);
}