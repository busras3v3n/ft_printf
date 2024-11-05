/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:13:48 by busseven          #+#    #+#             */
/*   Updated: 2024/11/05 12:49:43 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int ft_printf(const char *s, ...);
int ft_print_char(char c);
int ft_print_str(char *s);
int ft_print_nbr(int i);

#endif