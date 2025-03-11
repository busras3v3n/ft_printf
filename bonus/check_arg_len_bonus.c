/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_len_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:10:11 by busseven          #+#    #+#             */
/*   Updated: 2025/03/11 11:16:26 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	num_len_base(int base, unsigned long long i)
{
	int len;

	len = 1;
	while(i / base != 0)
	{
		i = i / base;
		len++;
	}
	return(len);
}

int	get_hexlen(t_flags *flags, unsigned int i)
{
	int	total_len;

	total_len = 0;
	if(flags->hash != 0)
		total_len += 2;
	if(num_len_base(16, i) > flags->precision)
		total_len += num_len_base(16, (unsigned long long) i);
	else
		total_len += flags->precision;
	return(total_len);
}

int	get_intlen_and_sign(t_flags *flags, int i)
{
	int	total_len;

	total_len = 0;
	if(flags->space != 0)
		total_len++;
	if(i < 0 || flags->plus != 0)
		total_len++;
	if(i < 0)
	{
		flags->isnegative = 1;
		i = -i;
	}
	if(num_len_base(10, i) > flags->precision)
		total_len += num_len_base(10, (unsigned long long) i);
	else
		total_len += flags->precision;
	return(total_len);
}

int	get_uintlen(t_flags *flags, unsigned int i)
{
	int	total_len;

	total_len = 0;
	if(num_len_base(10, i) > flags->precision)
		total_len += num_len_base(10, (unsigned long long) i);
	else
		total_len += flags->precision;
	return(total_len);
}

int	get_ptrlen(t_flags *flags, void *ptr)
{
	int	total_len;
	
	if (p == 0)
		return (5);
	total_len = 2;
	total_len += num_len_base(16, (unsigned long long) ptr);
}