/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:10:11 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 11:22:11 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	num_len_base(int base, unsigned long long i)
{
	int	len;

	len = 1;
	while (i / base != 0)
	{
		i = i / base;
		len++;
	}
	return (len);
}

void	get_hexlen_and_ifzero(t_flags *flags, unsigned int i)
{
	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
	{
		flags->len = 0;
		return ;
	}
	if (i == 0)
		flags->iszero = 1;
	else
		flags->iszero = 0;
	if (flags->hash != 0 && !flags->iszero)
		flags->len += 2;
	flags->len += bigger(num_len_base(16, i), flags->precision);
}

void	get_intlen_and_sign(t_flags *flags, int i)
{
	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
	{
		flags->len = 0;
		return ;
	}
	if (flags->space != 0)
		flags->len++;
	else if (i < 0 || flags->plus != 0)
		flags->len++;
	if (i < 0)
		flags->isnegative = 1;
	else
		flags->isnegative = 0;
	if (i == -2147483648)
		flags->len += bigger(10, flags->precision);
	else
		flags->len += bigger(num_len_base(10, absolute(i)), flags->precision);
}

void	get_uintlen(t_flags *flags, unsigned int i)
{
	if (flags->prec_stat != 0 && flags->precision == 0 && !i)
		flags->len = 0;
	else
		flags->len = bigger(num_len_base(10, i), flags->precision);
}

void	get_ptrlen(t_flags *flags, void *ptr)
{
	if (ptr == 0)
		flags->len = 5;
	else
		flags->len = 2 + num_len_base(16, (unsigned long long) ptr);
}
