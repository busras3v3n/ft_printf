/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:44:19 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:11:33 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reset_flags(t_flags *flags)
{
	flags->dash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->pad_num = 0;
	flags->precision = 0;
	flags->prec_stat = 0;
	flags->var_type = 0;
	if (flags->valid)
		free(flags->valid);
	flags->valid = ft_strdup("cspdiuxX%0-+ #.");
}

void	check_width(t_flags *flags, const char *s, va_list *args)
{
	char	*ptr;
	char	*pre_str;
	int		i;

	if (s[flags->i] == '*')
	{
		flags->pad_num = va_arg(*args, int);
		flags->i++;
	}
	else if (ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while (ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(s, 0, i);
		flags->pad_num = ft_atoi(pre_str);
		free(pre_str);
		flags->i = i;
	}
	else if (!is_valid_flag(s[flags->i], flags->valid))
		incomplete_format(flags);
}

void	check_precision(t_flags *flags, const char *s, va_list *args)
{
	char	*ptr;
	char	*pre_str;
	int		i;

	flags->i++;
	flags->prec_stat = 1;
	if (s[flags->i] == '*')
	{
		flags->precision = va_arg(*args, int);
		flags->i++;
	}
	else if (ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while (ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(s, 0, i);
		flags->precision = ft_atoi(pre_str);
		free(pre_str);
		flags->i = i;
	}
	else if (!is_valid_flag(s[flags->i], flags->valid))
		incomplete_format(flags);
}

void	which_flag(t_flags *flags, const char *s)
{
	if (s[flags->i] == '0')
		flags->zero = 1;
	else if (s[flags->i] == '+')
		flags->sign = 1;
	else if (s[flags->i] == '-')
		flags->left_justify == 1;
	else if (s[flags->i] == ' ')
		flags->space = 1;
	else if (s[flags->i] == '#')
		flags->hash == 1;
	flags->i++;
}
