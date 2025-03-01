/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:22:36 by busseven          #+#    #+#             */
/*   Updated: 2025/03/01 13:40:45 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_conflicting_flags(t_flags *flags)
{
	if(flags->space_flag != 0 && flags->sign != 0)
	{
		write("Error\nCan't have ' ' with '+'\n", 30);
		exit(1);
	}
	else if(flags->left_justify != 0 && flags->zero != 0)
	{
		write("Error\nCan't have '0' with '-'\n", 30);
		exit(1);
	}
}
void	incomplete_format(t_flags *flags)
{
	write(2, "Error\nincomplete or wrong format", 23);
	free(flags);
	exit(1);
}