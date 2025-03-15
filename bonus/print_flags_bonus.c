/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:47:14 by busseven          #+#    #+#             */
/*   Updated: 2025/03/15 16:02:02 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_nbr_absolute(t_flags *flags, int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		flags->count += 10;
	}
	else if (n < 0)
		ft_print_nbr_absolute(flags, -n);
	else if (n > 9)
	{
		ft_print_nbr_absolute(flags, n / 10);
		ft_print_nbr_absolute(flags, n % 10);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write(1, &c, 1);
		flags->count++;
	}
}

void	print_padding(t_flags *flags)
{
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
	if(flags->hash != 0 && !flags->iszero)
	{
		if((flags->hash != 0 && flags->type == 'x'))
			write(1, "0x", 2);
		else if(flags->hash != 0 && flags->type == 'X')
			write(1, "0X", 2);
		flags->count += 2;
	}
}

void	print_sign(t_flags *flags)
{
	if(flags->plus || flags->isnegative)
	{
		if(flags->isnegative)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		flags->count++;
	}
}

void	print_space(t_flags *flags)
{
	if(flags->space && !flags->isnegative && flags->type != 's')
	{
		write(1, " ", 1);
		flags->count++;
	}
}
