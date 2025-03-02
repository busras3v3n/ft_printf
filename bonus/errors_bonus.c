/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:22:36 by busseven          #+#    #+#             */
/*   Updated: 2025/03/02 17:06:08 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	undefined_flag_combination(t_flags *flags)
{
	write("Error\ninvalid flag combination\n", 30);
	free_flag_struct(flags);
	exit(1);
}

void	incomplete_format(t_flags *flags)
{
	write(2, "Error\nincomplete or wrong format", 23);
	free(flags);
	exit(1);
}

void	plus_and_space(t_flags *flags)
{
	write("Error\ncan't have ' ' with '+'\n", 30);
	free(flags);
	exit(1);
}

void	zero_and_dash(t_flags *flags)
{
	write("Error\ncan't have '0' with '-'\n", 30);
	free(flags);
	exit(1);
}
