/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:41:01 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 11:27:54 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_value(t_flags *flags, va_list *args)
{
	char	c;

	c = flags->type;
	if (flags->prec_stat)
		print_precision(flags, args);
	if (c == 'c')
		flags->count += ft_print_char(va_arg(*args, int));
	else if (c == 's')
		flags->count += ft_print_str_b(flags, va_arg(*args, char *));
	else if (c == 'i' || c == 'd')
		ft_print_nbr_absolute(flags, va_arg(*args, int), 1);
	else if (c == 'u')
		flags->count += ft_print_unbr_b(va_arg(*args, unsigned int), 1, flags);
	else if (c == 'x' || c == 'X')
		flags->count += ft_print_hex_b(va_arg(*args, unsigned int), c, flags);
	else if (c == 'p')
		flags->count += ft_print_ptr(va_arg(*args, void *));
}

void	print_with_flags(const char *s, va_list *args, t_flags *flags)
{
	flags->type = s[flags->i];
	if (flags->type == '%')
	{
		write(1, "%", 1);
		flags->count++;
		return ;
	}
	check_arg_len(flags, args);
	flags->pad_len = flags->width - flags->len;
	if (!flags->dash)
		print_padding(flags);
	if (!flags->zero)
		print_sign(flags);
	print_space(flags);
	print_hash(flags);
	print_value(flags, args);
	if (flags->dash && flags->pad_len > 0)
		print_padding(flags);
}
