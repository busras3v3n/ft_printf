/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:37:43 by busseven          #+#    #+#             */
/*   Updated: 2025/03/15 16:07:24 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_precision_hex(t_flags *flags, unsigned int i)
{
	int n;
	int	count;

	n = flags->len - num_len_base(16, (unsigned long long)i);
	if(flags->hash)
		n -= 2;
	count = n;
	while(n > 0)
	{
		write(1, "0", 1);
		n--;
	}
	return(count);
}

void	print_precision_int(t_flags *flags, int i)
{
	int n;
	
	if(i < 0)
		i = -i;
	n = flags->len - num_len_base(10, (unsigned long long)i);
	if(flags->isnegative || flags->plus || flags->space)
		n--;
	while(n > 0)
	{
		write(1, "0", 1);
		flags->count++;
		n--;
	}
}

void	print_precision_uint(t_flags *flags, unsigned int i)
{
	int n;
	
	n = flags->len - num_len_base(10, (unsigned long long)i);
	if(flags->isnegative || flags->plus || flags->space)
		n--;
	while(n > 0)
	{
		write(1, "0", 1);
		flags->count++;
		n--;
	}
}

int	ft_print_str_precision(t_flags *flags, char *s)
{
	int i = 0;
	if(flags->prec_stat != 0)
	{
		while(flags->precision > 0 && s[i])
		{
			write(1, &s[i], 1);
			i++;
			flags->precision--;
		}
		return(i);
	}
	else
		return(ft_print_str(s));
}

void	print_precision(t_flags *flags, va_list *args)
{
	va_list	args_copy;

	va_copy(args_copy, *args);
	if(flags->type == 'i' || flags->type == 'd')
		print_precision_int(flags, va_arg(args_copy, int));
	else if(flags->type == 'u')
		print_precision_uint(flags, va_arg(args_copy, unsigned int));
	else if(flags->type == 'x' || flags->type == 'X')
		flags->count += print_precision_hex(flags, va_arg(args_copy, unsigned int));
}