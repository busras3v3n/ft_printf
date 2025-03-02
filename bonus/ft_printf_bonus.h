/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:48 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:10:02 by busseven         ###   ########.fr       */
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
void	look_for_flags(t_flags *flags, const char *s);
void	reset_flags(t_flags *flags);
void	assign_flag_str(t_flags *flags);
void	free_flag_struct(t_flags *flags);

#endif