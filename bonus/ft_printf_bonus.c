/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:10:16 by busseven          #+#    #+#             */
/*   Updated: 2025/03/17 14:12:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_flags(const char *s, va_list *args, t_flags *flags)
{
	while (s[flags->i])
	{
		if (is_in_str(s[flags->i], "cspdiuxX%"))
		{
			print_with_flags(s, args, flags);
			return ;
		}
		else if (s[flags->i] == '.')
			check_precision(flags, s, args);
		else if (s[flags->i] != '0' && (ft_isdigit(s[flags->i]) || s[flags->i] == '*'))
			check_width(flags, s, args);
		else
			which_flag(flags, s);
	}
}

void	handle_print(const char *s, va_list *args, t_flags *flags)
{
	while (s[flags->i])
	{
		if (s[flags->i] == '%')
		{
			flags->i++;
			handle_flags(s, args, flags);
			reset_flags(flags);
		}
		else
		{
			ft_putchar_fd(s[flags->i], 1);
			flags->count++;
		}
		flags->i++;
	}
}

int	ft_printf(const char *s, ...)
{
	t_flags	*flags;
	int	count;
	va_list	args;

	va_start(args, s);
	flags = ft_calloc(1, sizeof(t_flags));
	flags->i = 0;
	reset_flags(flags);
	handle_print(s, &args, flags);
	count = flags->count;
	if(flags)
		free(flags);
	va_end(args);
	return (count);
}
