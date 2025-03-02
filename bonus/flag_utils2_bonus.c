/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:41:01 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:41:10 by busseven         ###   ########.fr       */
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
	check_type_and_flag_validity(s, flags);
	(void)args;
	reset_flags(flags);
}
