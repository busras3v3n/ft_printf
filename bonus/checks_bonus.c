/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:34:53 by busseven          #+#    #+#             */
/*   Updated: 2025/03/13 11:16:16 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_conflicting_flags(t_flags *flags)
{
	if (flags->space != 0 && flags->plus != 0)
		plus_and_space(flags);
	else if (flags->dash != 0 && flags->zero != 0)
		zero_and_dash(flags);
}
