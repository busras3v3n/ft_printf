/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:47:14 by busseven          #+#    #+#             */
/*   Updated: 2025/03/13 17:31:53 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_nbr_absolute(int i)
{
	if(i < 0)
		i = -i;
	ft_putnbr_fd(i, 1);
	return (num_len_base(10, (unsigned long long)i));
}

int	print_padding(t_flags *flags)
{
	int count;
	
	count = 0;
	while(flags->pad_len > 0)
	{
		if(!flags->dash && flags->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
		flags->pad_len--;
	}
	return(count);
}
int	print_hash(t_flags *flags)
{
	char	type;

	type = flags->type;
	if(flags->hash != 0)
	{
		if((flags->hash != 0 && type == 'x'))
			write(1, "0x", 2);
		else if(flags->hash != 0 && type == 'X')
			write(1, "0X", 2);
		return(2);
	}
	return(0);
}
int	print_sign(t_flags *flags)
{
	if(flags->plus && !flags->isnegative)
	{
		write(1, "+", 1);
		return(1);
	}
	return(0);
}
int	print_space(t_flags *flags)
{
	if(flags->space && !flags->isnegative)
	{
		write(1, " ", 1);
		return(1);
	}
	return(0);
}