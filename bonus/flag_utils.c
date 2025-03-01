/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:44:19 by busseven          #+#    #+#             */
/*   Updated: 2025/03/01 16:00:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_width(t_flags *flags, char *s, va_list *args)
{
	char	*ptr;
	char	*pre_str;
	int		i;

	if(s[flags->i] == '*')
	{
		flags->padding_number = va_arg(*args, int);
		flags->i++;
	}
	else if(ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while(ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(s, 0, i);
		flags->padding_number = ft_atoi(pre_str);
		free(pre_str);
		flags->i = i;
	}
	else if(!is_valid_flag(s[flags->i], flags->valid))
		incomplete_format(flags);
}

void	check_precision(t_flags *flags, char *s, va_list *args)
{
	char	*ptr;
	char	*pre_str;
	int		i;

	flags->i++;
	if(s[flags->i] == '*')
	{
		flags->precision_number = va_arg(*args, int);
		flags->i++;
	}
	else if(ft_isdigit(s[flags->i]))
	{
		i = 0;
		ptr = s + flags->i;
		while(ft_isdigit(ptr[i]))
			i++;
		pre_str = ft_substr(s, 0, i);
		flags->precision_number = ft_atoi(pre_str);
		free(pre_str);
		flags->i = i;
	}
	else if(!is_valid_flag(s[flags->i], flags->valid))
		incomplete_format(flags);
}	
void	check_flag(t_flags *flags, char *s)
{
	if(s[flags->i] == '0')
		flags->zero = 1;
	else if(s[flags->i] == '+')
		flags->sign = 1;
	else if(s[flags->i] == '-')
		flags->left_justify == 1;
	else if(s[flags->i] == ' ')
		flags->space_flag = 1;
	else if(s[flags->i] == '#')
		flags->hash == 1;
	flags->i++;
}