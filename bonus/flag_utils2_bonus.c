/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:41:01 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 18:16:36 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	va_list	*args_copy;

	va_copy(args_copy, args);
	check_type_and_flag_validity(s, flags);
	flags->type = s[flags->i];
	// tip % ise yazdır ve dön geç
	//check_arg_len(flags, args_copy);
	flags->pad_len = flags->width - flags->len;
	if(!flags->dash)
		print_padding(flags);
	//print_hash()
	//print_sign()
	//print_space()
	//print_value()
	//print_padding()
	//hash varsa x0, işaret varsa işaret, boşluk varsa boşluk.
	// precision'u göze alarak değerin kendisini yazdır, stringse precision kadar,(en fazla) negatif sayıysa mutlak değer.
	// dash varsa sona padding yazdır.
}
