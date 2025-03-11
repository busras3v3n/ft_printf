/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:47:14 by busseven          #+#    #+#             */
/*   Updated: 2025/03/11 17:36:54 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_padding(t_flags *flags)
{
	int count;
	
	count = 0;
	while(flags->pad_len > 0)
	{
		if(flags->zero)
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
	if(flags->hash != 0 || type == 'p')
	{
		if((flags->hash != 0 && type == 'x') || type == 'p')
			write(1, "0x", 2);
		else if(flags->hash != 0 && type == 'X')
			write(1, "0X", 2);
		return(2);
	}
	return(0);
}
int	print_sign(t_flags *flags)
{
	if(flags->isnegative || flags->plus != 0)
	{
		if(flags->isnegative)
			write(1, "-", 1);
		else if(flags->plus)
			write(1, "+", 1);
		return(1);
	}
	return(0);
}
int	print_space(t_flags *flags)
{
	if(flags->space)
	{
		write(1, " ", 1);
		return(1);
	}
	return(0);
}