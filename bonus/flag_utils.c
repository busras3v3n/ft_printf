/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:44:19 by busseven          #+#    #+#             */
/*   Updated: 2025/02/28 19:49:42 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_precision(t_flags *flags, char *s)
{
	flags->i++;
	if(s[flags->i] == '*')
		flags->precision_number = va_arg(*args, int);
	else
	{
		while(1)
		{
			if(is_type_flag(s[flags->i]))
				return;
			else if()
		}
	}
}