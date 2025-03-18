/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:35:28 by busseven          #+#    #+#             */
/*   Updated: 2025/03/18 09:56:14 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	smaller(int a, int b)
{
	if(a > b)
		return(a);
	else
		return(b);
}

int	bigger(int a, int b)
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
