/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:48 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:40:42 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../ft_printf.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		dash;
	int		space;
	int		plus;
	int		hash;
	int		zero;
	int		pad_num;
	int		precision;
	int		var_type;
	int		count;
	int		prec_stat;
	int		i;
	char	*valid;
	char	*f_width;
	char	*f_dash;
	char	*f_prec;
	char	*f_zero;
	char	*f_space;
	char	*f_plus;
	char	*f_hash;
}	t_flags;

void	incomplete_format(t_flags *flags);
void	check_conflicting_flags(t_flags *flags);
int		is_in_str(char c, char *str);
void	print_with_flags(const char *s, va_list *args, t_flags *flags);
void	found_dot(t_flags *flags, const char *s, va_list *args);
void	found_field_width(t_flags *flags, const char *s, va_list *args);
void	which_flag(t_flags *flags, const char *s);
void	reset_flags(t_flags *flags);
void	assign_flag_str(t_flags *flags);
void	free_flag_struct(t_flags *flags);
void	undefined_flag_combination(t_flags *flags);
void	plus_and_space(t_flags *flags);
void	zero_and_dash(t_flags *flags);
char	*change_string_with(char *before, const char *after);
void	check_precision(t_flags *flags, const char *s, va_list *args);
void	check_width(t_flags *flags, const char *s, va_list *args);
void	check_type_and_flag_validity(const char *s, t_flags *flags);

#endif