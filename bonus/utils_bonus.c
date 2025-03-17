/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:35:28 by busseven          #+#    #+#             */
/*   Updated: 2025/03/17 16:07:10 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	return_bigger(int a, int b)
{
	if(a > b)
		return(a);
	else
		return(b);
}
int absolute(int i)
{
	if(i < 0)
		return(-i);
	else
		return(i);
}
int	ft_print_hex_prec(int i, char s, t_flags *flags)
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

int	ft_print_unbr_prec(unsigned int n, int fd, t_flags *flags)
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

int	is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
