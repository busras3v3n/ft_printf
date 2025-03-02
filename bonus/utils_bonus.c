/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:35:28 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:42:47 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

char	*change_string_with(char *before, const char *after)
{
	free(before);
	return (ft_strdup(after));
}

void	free_flag_struct(t_flags *flags)
{
	free(flags->valid);
	free(flags->f_width);
	free(flags->f_dash);
	free(flags->f_prec);
	free(flags->f_zero);
	free(flags->f_space);
	free(flags->f_plus);
	free(flags->f_hash);
	free(flags);
}
