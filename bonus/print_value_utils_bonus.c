/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_value_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:37:43 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 10:00:20 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_nbr_absolute(t_flags *flags, int n, int first)
{
	char	c;

	if(flags->prec_stat != 0 && flags->precision == 0 && !n && first)
		return ;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		flags->count += 10;
	}
	else if (n < 0)
		ft_print_nbr_absolute(flags, -n, 0);
	else if (n > 9)
	{
		ft_print_nbr_absolute(flags, n / 10, 0);
		ft_print_nbr_absolute(flags, n % 10, 0);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write(1, &c, 1);
		flags->count++;
	}
}

int	ft_print_hex_wprec(int i, char s, t_flags *flags)
{
	unsigned int	u;

	u = (unsigned int)i;
	if(flags->prec_stat != 0 && flags->precision == 0 && i == 0)
		return (0);
	if (s == 'x')
		return (ft_putnbr_hex_fd(u, 1));
	if (s == 'X')
		return (ft_putnbr_hex_upcase_fd(u, 1));
	else
		return (0);
}

int	ft_print_unbr_wprec(unsigned int n, int fd, t_flags *flags)
{
	char	c;
	int		ret;

	if(flags->prec_stat != 0 && flags->precision == 0 && n == 0)
		return (0);
	ret = 0;
	if (n > 9)
	{
		ret += ft_print_unbr(n / 10, fd);
		ret += ft_print_unbr(n % 10, fd);
	}
	else if (n <= 9)
	{
		c = '0' + n;
		write(fd, &c, 1);
		ret++;
	}
	return (ret);
}
int	ft_print_str_wprec(t_flags *flags, char *s)
{
	int i = 0;
	
	if(flags->prec_stat != 0 && flags->precision < 6 && !s)
		return 0;
	if(flags->prec_stat != 0 && s)
	{
		while(flags->precision > 0 && s[i])
		{
			write(1, &s[i], 1);
			i++;
			flags->precision--;
		}
		return(i);
	}
	else
		return(ft_print_str(s));
}