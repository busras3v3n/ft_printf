/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:41:52 by busseven          #+#    #+#             */
/*   Updated: 2024/11/06 10:00:57 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void ft_putnbr_hex_fd(int n, int fd)
{
    char    *base
    int     count;

    base = "0123456789abcdef";
    count = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
        count++;
		count += ft_putnbr_hex_fd(-n, fd);
	}
	else if (n > 16)
	{
		count += ft_putnbr_hex_fd(n / 16, fd);
		count += ft_putnbr_hex_fd(n % 16, fd);
	}
	else if (n >= 0 && n <= 16)
	{
		write(fd, &base[n], 1);
        count++;
	}
    return (count);
}
static void ft_putnbr_hex_upcase_fd(int n, int fd)
{
    char    *base
    int     count;

    base = "0123456789ABCDEF";
    count = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
        count++;
		count += ft_putnbr_hex_fd(-n, fd);
	}
	else if (n > 16)
	{
		count += ft_putnbr_hex_fd(n / 16, fd);
		count += ft_putnbr_hex_fd(n % 16, fd);
	}
	else if (n >= 0 && n <= 16)
	{
		write(fd, &base[n], 1);
        count++;
	}
    return (count);
}

int ft_print_hex(int i, char s)
{
    if(s == 'x')
        return(ft_putnbr_hex_fd(i, 1));
    if(s == 'X')
        return(ft_putnbr_hex_upcase_fd(i, 1));
}