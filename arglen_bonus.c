/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:59:47 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 11:21:56 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_strlen(t_flags *flags, char *str)
{
	if (flags->prec_stat != 0)
	{
		if ((flags->precision < 6 && !str) || !flags->precision)
			flags->len = 0;
	}
	if (!str)
		flags->len = 6;
	else if (flags->prec_stat)
		flags->len = smaller(flags->precision, (int)ft_strlen(str));
	else
		flags->len = ft_strlen(str);
}

void	check_arg_len(t_flags *flags, va_list *args)
{
	va_list	args_copy;

	va_copy(args_copy, *args);
	if (flags->type == 's')
		get_strlen(flags, va_arg(args_copy, char *));
	else if (flags->type == 'i' || flags->type == 'd')
		get_intlen_and_sign(flags, va_arg(args_copy, int));
	else if (flags->type == 'u')
		get_uintlen(flags, va_arg(args_copy, unsigned int));
	else if (flags->type == 'c')
		flags->len = 1;
	else if (flags->type == 'x' || flags->type == 'X')
		get_hexlen_and_ifzero(flags, va_arg(args_copy, int));
	else if (flags->type == 'p')
		get_ptrlen(flags, va_arg(args_copy, void *));
	va_end(args_copy);
}
