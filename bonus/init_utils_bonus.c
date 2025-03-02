/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:04:10 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:41:34 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	assign_flag_str(t_flags *flags)
{
	flags->f_width = ft_strdup("cspdiuxX%");
	flags->f_dash = ft_strdup("cspdiuxX%");
	flags->f_prec = ft_strdup("sdiuxX%");
	flags->f_zero = ft_strdup("diuxX%");
	flags->f_space = ft_strdup("di%");
	flags->f_plus = ft_strdup("pdi%");
	flags->f_hash = ft_strdup("xX%");
}
