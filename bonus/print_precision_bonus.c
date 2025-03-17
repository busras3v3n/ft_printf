/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:37:43 by busseven          #+#    #+#             */
/*   Updated: 2025/03/17 15:48:08 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_precision_hex(t_flags *flags, unsigned int i)
{
	int n;
	int	count;

	if(flags->prec_stat != 0 && flags->precision == 0 && !i)
		return 0;
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
	int num_len;
	
	if(flags->prec_stat != 0 && flags->precision == 0 && !i)
		return ;
	if(i == -2147483648)
		num_len = 10;
	else if(i < 0)
	{
		i = -i;
		num_len = num_len_base(10, (unsigned long long)i);
	}
	else
		num_len = num_len_base(10, (unsigned long long)i);
	n = flags->len - num_len;
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
	
	if(flags->prec_stat != 0 && flags->precision == 0 && !i)
		return ;
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
	
	if(flags->prec_stat != 0 && flags->precision < 6 && !s)
		return 0;
	if(flags->prec_stat != 0 && s)
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