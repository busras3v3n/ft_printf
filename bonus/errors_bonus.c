/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:22:36 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 13:36:41 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	undefined_flag_type(t_flags *flags)
{
	write("Error\ninvalid flag combination\n", 30);
	free_flag_struct(flags);
	exit(1);
}

void	check_conflicting_flags(t_flags *flags)
{
	if(flags->space != 0 && flags->sign != 0)
	{
		write("Error\ncan't have ' ' with '+'\n", 30);
		free(flags);
		exit(1);
	}
	else if(flags->dash != 0 && flags->zero != 0)
	{
		write("Error\ncan't have '0' with '-'\n", 30);
		free(flags);
		exit(1);
	}
}

void	incomplete_format(t_flags *flags)
{
	write(2, "Error\nincomplete or wrong format", 23);
	free(flags);
	exit(1);
}