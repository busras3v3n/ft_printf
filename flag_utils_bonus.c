/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:44:19 by busseven          #+#    #+#             */
/*   Updated: 2025/03/17 15:11:38 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_flags(t_flags *flags)
{
	flags->isnegative = 0;
	flags->dash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->prec_stat = 0;
	flags->len = 0;
	flags->iszero = 0;
	flags->pad_len = 0;
	flags->type = '0';
}

void	check_width(t_flags *flags, const char *s, va_list *args)
{
	const char	*ptr;
	char	*pre_str;
	int		i;

	if (s[flags->i] == '*')
	{
		flags->width = va_arg(*args, int);
		flags->i++;
	}
	else if (ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while (ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(ptr, 0, i);
		flags->width = ft_atoi(pre_str);
		flags->i += ft_strlen(pre_str);
		free(pre_str);
	}
}

void	check_precision(t_flags *flags, const char *s, va_list *args)
{
	const char	*ptr;
	char	*pre_str;
	int		i;

	flags->i++;
	flags->prec_stat = 1;
	if (s[flags->i] == '*')
	{
		flags->precision = va_arg(*args, int);
		flags->i++;
	}
	else if (ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while (ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(ptr, 0, i);
		flags->precision = ft_atoi(pre_str);
		flags->i += ft_strlen(pre_str);
		free(pre_str);
	}
}

void	which_flag(t_flags *flags, const char *s)
{
	if (s[flags->i] == '0')
		flags->zero = 1;
	else if (s[flags->i] == '+')
		flags->plus = 1;
	else if (s[flags->i] == '-')
		flags->dash = 1;
	else if (s[flags->i] == ' ')
		flags->space = 1;
	else if (s[flags->i] == '#')
		flags->hash = 1;
	flags->i++;
}
