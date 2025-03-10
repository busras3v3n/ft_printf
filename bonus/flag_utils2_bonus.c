/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:41:01 by busseven          #+#    #+#             */
/*   Updated: 2025/03/10 12:45:47 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_arg_len(t_flags *flags, va_list *args)
{
	va_list args_copy;

	va_copy(args_copy, args);
	if(flags->type == 's')
		flags->len = flags->precision;
	else if(flags->type == 'i' || flags->type == 'd')
		flags->len = get_intlen(flags, va_arg(args_copy, int));
	else if(flags->type == 'u')
		flags->len = get_uintlen(flags, va_arg(args_copy, unsigned int));
	else if(flags->type == 'c')
		flags->len = 1;
	else if(flags->type == 'x' || flags->type == 'X')
		flags->len = get_hexlen(flags, va_arg(args_copy, int));
	else if(flags->type == 'p')
		flags->len = get_ptrlen(flags, va_arg(args_copy, void *));
	va_end(args_copy);
}
void	found_dot(t_flags *flags, const char *s, va_list *args)
{
	flags->valid = change_string_with(flags->valid, "cspdiuxX%");
	check_precision(flags, s, args);
}

void	found_field_width(t_flags *flags, const char *s, va_list *args)
{
	flags->valid = change_string_with(flags->valid, "cspdiuxX%.");
	check_width(flags, s, args);
}

void	print_with_flags(const char *s, va_list *args, t_flags *flags)
{
	check_type_and_flag_validity(s, flags);
	flags->type = s[flags->i];
	if(flags->type = '%')
	{
		write(1, "%", 1);
		return;
	}
	check_arg_len(flags, args);
	flags->pad_len = flags->width - flags->len;
	if(!flags->dash)
		print_padding(flags);
	//print_hash()
	//print_sign()
	//print_space()
	//print_value()
	if(!flags->dash)
		//print_padding()
	//hash varsa x0, işaret varsa işaret, boşluk varsa boşluk.
	// precision'u göze alarak değerin kendisini yazdır, stringse precision kadar,(en fazla) negatif sayıysa mutlak değer.
	// dash varsa sona padding yazdır.
}
