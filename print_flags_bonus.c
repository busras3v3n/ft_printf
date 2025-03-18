/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:47:14 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 11:16:54 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_padding_before(t_flags *flags)
{
	while (flags->pad_len > 0)
	{
		if (!flags->dash && flags->zero && !flags->prec_stat)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flags->count++;
		flags->pad_len--;
	}
}

void	print_padding(t_flags *flags)
{
	if (flags->prec_stat)
		flags->zero = 0;
	if (flags->zero)
		print_sign(flags);
	while (flags->pad_len > 0)
	{
		if (!flags->dash && flags->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flags->count++;
		flags->pad_len--;
	}
}

void	print_hash(t_flags *flags)
{
	if (flags->hash != 0 && !flags->iszero)
	{
		if ((flags->hash != 0 && flags->type == 'x'))
			write(1, "0x", 2);
		else if (flags->hash != 0 && flags->type == 'X')
			write(1, "0X", 2);
		flags->count += 2;
	}
}

void	print_sign(t_flags *flags)
{
	if (flags->plus || flags->isnegative)
	{
		if (flags->isnegative)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		flags->count++;
	}
}

void	print_space(t_flags *flags)
{
	if (flags->space && !flags->isnegative && flags->type != 's')
	{
		write(1, " ", 1);
		flags->count++;
	}
}
