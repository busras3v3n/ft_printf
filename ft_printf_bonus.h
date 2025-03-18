/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:48 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 18:56:20 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_flags
{
	int		dash;
	int		space;
	int		plus;
	int		hash;
	int		zero;
	int		width;
	int		precision;
	int		count;
	int		prec_stat;
	int		i;
	char	type;
	int		len;
	int		pad_len;
	int		isnegative;
	int		iszero;
}	t_flags;

void		incomplete_format(t_flags *flags);
int			is_in_str(char c, char *str);
void		print_with_flags(const char *s, va_list *args, t_flags *flags);
void		which_flag(t_flags *flags, const char *s);
void		reset_flags(t_flags *flags);
void		check_precision(t_flags *flags, const char *s, va_list *args);
void		check_width(t_flags *flags, const char *s, va_list *args);
int			num_len_base(int base, unsigned long long i);
void		get_intlen_and_sign(t_flags *flags, int i);
void		get_hexlen_and_ifzero(t_flags *flags, unsigned int i);
void		get_uintlen(t_flags *flags, unsigned int i);
void		get_ptrlen(t_flags *flags, void *ptr);
void		print_space(t_flags *flags);
void		print_sign(t_flags *flags);
void		print_hash(t_flags *flags);
void		print_padding(t_flags *flags);
void		ft_print_nbr_absolute(t_flags *flags, int i, int first);
void		print_precision(t_flags *flags, va_list *args);
int			ft_print_str_b(t_flags *flags, char *s);
void		check_arg_len(t_flags *flags, va_list *args);
int			ft_print_hex_b(int i, char s, t_flags *flags);
int			ft_print_unbr_b(unsigned int n, int fd, t_flags *flags);
int			absolute(int i);
int			smaller(int a, int b);
int			bigger(int a, int b);

#endif