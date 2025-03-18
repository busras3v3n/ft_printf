/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:55:43 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 11:31:03 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_prec_hex(t_flags *flags, unsigned int i)
{
	int	n;
	int	count;

	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
		return (0);
	n = flags->len - num_len_base(16, (unsigned long long)i);
	if (flags->hash)
		n -= 2;
	count = n;
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
	return (count);
}

void	print_precision_int(t_flags *flags, int i)
{
	int	n;
	int	num_len;

	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
		return ;
	if (i == -2147483648)
		num_len = 10;
	else if (i < 0)
	{
		i = -i;
		num_len = num_len_base(10, (unsigned long long)i);
	}
	else
		num_len = num_len_base(10, (unsigned long long)i);
	n = flags->len - num_len;
	if (flags->isnegative || flags->plus || flags->space)
		n--;
	while (n > 0)
	{
		write(1, "0", 1);
		flags->count++;
		n--;
	}
}

void	print_precision_uint(t_flags *flags, unsigned int i)
{
	int	n;

	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
		return ;
	n = flags->len - num_len_base(10, (unsigned long long)i);
	if (flags->isnegative || flags->plus || flags->space)
		n--;
	while (n > 0)
	{
		write(1, "0", 1);
		flags->count++;
		n--;
	}
}

void	print_precision(t_flags *flags, va_list *args)
{
	va_list	args_copy;
	char	c;

	c = flags->type;
	va_copy(args_copy, *args);
	if (c == 'i' || c == 'd')
		print_precision_int(flags, va_arg(args_copy, int));
	else if (c == 'u')
		print_precision_uint(flags, va_arg(args_copy, unsigned int));
	else if (c == 'x' || c == 'X')
		flags->count += print_prec_hex(flags, va_arg(args_copy, unsigned int));
}
