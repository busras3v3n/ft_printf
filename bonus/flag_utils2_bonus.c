/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:41:01 by busseven          #+#    #+#             */
/*   Updated: 2025/03/13 17:09:12 by busseven         ###   ########.fr       */
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
	n = flags->len - num_len_base(10, (unsigned long long)i) - flags->isnegative;
	if(flags->isnegative || flags->plus || flags->space)
		n--;
	while(n > 0)
	{
		write(1, "0", 1);
		flags->count++;
		n--;
	}
}
void	print_precision(t_flags *flags, va_list *args)
{
	va_list	args_copy;

	va_copy(args_copy, *args);
	if(flags->type == 'i' || flags->type == 'd')
		print_precision_int(flags, va_arg(args_copy, int));
	else if(flags->type == 'x' || flags->type == 'X')
		flags->count += print_precision_hex(flags, va_arg(args_copy, unsigned int));
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

void	print_value(t_flags *flags, va_list *args)
{
	if(flags->precision > 0)
		print_precision(flags, args);
	if (flags->type == 'c')
		flags->count += ft_print_char(va_arg(*args, int));
	else if (flags->type == 's')
		flags->count += ft_print_str_precision(flags, va_arg(*args, char *));
	else if (flags->type == 'i' || flags->type == 'd')
		flags->count += ft_print_nbr_absolute(va_arg(*args, int));
	else if (flags->type == 'u')
		flags->count += ft_print_unbr(va_arg(*args, unsigned int), 1);
	else if (flags->type == 'x' || flags->type == 'X')
		flags->count += ft_print_hex(va_arg(*args, unsigned int), flags->type);
	else if (flags->type == 'p')
		flags->count += ft_print_ptr(va_arg(*args, void *));
}
int	get_strlen(t_flags *flags, char *str)
{
	if(flags->prec_stat && flags->precision < (int)ft_strlen(str))
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
		flags->len = get_hexlen(flags, va_arg(args_copy, int));
	else if(flags->type == 'p')
		flags->len = get_ptrlen(va_arg(args_copy, void *));
	va_end(args_copy);
}
void	found_dot(t_flags *flags, const char *s, va_list *args)
{
	check_precision(flags, s, args);
}

void	found_field_width(t_flags *flags, const char *s, va_list *args)
{
	check_width(flags, s, args);
}

void	print_with_flags(const char *s, va_list *args, t_flags *flags)
{
	flags->type = s[flags->i];
	if(flags->type == '%')
	{
		write(1, "%", 1);
		flags->count++;
		return;
	}
	check_arg_len(flags, args);
	flags->pad_len = flags->width - flags->len;
	if(!flags->dash && flags->pad_len > 0)
		flags->count += print_padding(flags);
	flags->count += print_space(flags);
	flags->count += print_hash(flags);
	flags->count += print_sign(flags);
	print_value(flags, args);
	if(flags->dash && flags->pad_len > 0)
		flags->count += print_padding(flags);
}
