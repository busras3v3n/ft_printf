/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:34:53 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:12:36 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_conflicting_flags(t_flags *flags)
{
	if (flags->space != 0 && flags->sign != 0)
		plus_and_space(flags);
	else if (flags->dash != 0 && flags->zero != 0)
		zero_and_dash(flags);
}

void	check_type_and_flag_validity(const char *s, t_flags *flags)
{
	if (!is_in_str(s[flags->i], flags->f_hash) && flags->hash != 0)
		undefined_flag_combination(flags);
	if (!is_in_str(s[flags->i], flags->f_width) && flags->pad_num != 0)
		undefined_flag_combination(flags);
	if (!is_in_str(s[flags->i], flags->f_dash) && flags->dash != 0)
		undefined_flag_combination(flags);
	if (!is_in_str(s[flags->i], flags->f_zero) && flags->zero != 0)
		undefined_flag_combination(flags);
	if (!is_in_str(s[flags->i], flags->f_prec) && flags->prec_stat != 0)
		undefined_flag_combination(flags);
	if (!is_in_str(s[flags->i], flags->f_space) && flags->space != 0)
		undefined_flag_type(flags);
	if (!is_in_str(s[flags->i], flags->f_plus) && flags->plus != 0)
		undefined_flag_combination(flags);
}
