/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:48 by busseven          #+#    #+#             */
/*   Updated: 2025/02/28 16:06:10 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flags
{
	int	left_justify;
	int	space_sign;
	int	hash;
	int	padding_type;
	int padding_place;
	int	padding_number;
	int	precision_place;
	int	precision_number;
	char	var_type;
	int	len;
} t_flags;

int	ft_printf(const char *s, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int i);
int	ft_print_hex(unsigned int i, char s);
int	ft_print_ptr(void *p);
int	ft_print_unbr(unsigned int n, int fd);
int	ft_print_percent(void);

#endif