/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:34:53 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 13:35:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	assign_flag_types(t_flags *flags)
{
	flags->f_width = ft_strdup("cspdiuxX%");
	flags->f_dash = ft_strdup("cspdiuxX%");
	flags->f_prec = ft_strdup("sdiuxX%");
	flags->f_zero = ft_strdup("diuxX%");
	flags->f_space = ft_strdup("di%");
	flags->f_plus = ft_strdup("pdi%");
	flags->f_hash = ft_strdup("xX%");
}

void check_type_and_flag_validity(char **s, t_flags *flags)
{
	assign_flag_types(flags);
	if(!is_in_str(s[flags->i], flags->f_hash) && flags->hash != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_width) && flags->pad_num != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_dash) && flags->dash != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_zero) && flags->zero != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_prec) && flags->prec_stat != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_space) && flags->space != 0)
		undefined_flag_type(flags);
	if(!is_in_str(s[flags->i], flags->f_plus) && flags->plus != 0)
		undefined_flag_type(flags);
}