#include <stdio.h>
#include "ft_printf_bonus.h"

#include "../libft/libft.h"
#include <stdarg.h>

int	is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return(1);
		i++;
	}
	return(0);
}

void	ft_handleflags(const char *s, va_list *args, t_flags *flags)
{
	while(s[flags->i])
	{
		check_conflicting_flags(flags);
		if(!is_in_str(s[flags->i], flags->valid))
			incomplete_format(flags);
		else if(is_in_str(s[flags->i], "cspdiuxX%"))
		{
			print_with_flags(s, args, flags);
			reset_flags(flags);
			return;
		}
		else if(s[flags->i] == '.')
		{
			flags->valid = change_string_with(flags->valid, "cspdiuxX%");
			check_precision(flags, s, args);
		}
		else if(s[flags->i] != '0' && (ft_isdigit(s[flags->i]) || s[flags->i]== '*'))
		{
			flags->valid = change_string_with(flags->valid, "cspdiuxX%.");
			check_width(flags, s, args);
		}
		else
			check_flag(flags, s);
	}
	incomplete_format(flags);
}

void	handle_print(const char *s, va_list *args, t_flags *flags)
{
	while (s[flags->i])
	{
		if (s[flags->i] == '%')
		{
			flags->i++;
			ft_handleflags(s, args, flags);
		}
		else
		{
			ft_putchar_fd(s[flags->i], 1);
			flags->count++;
		}
		flags->i++;
	}
}
int	ft_printf(const char *s, ...)
{
	t_flags	*flags;
	va_list	args;

	va_start(args, s);
	flags = ft_calloc(1, sizeof(t_flags));
	flags->i = 0;
	reset_flags(flags);
	handle_print(s, &args, flags);
	va_end(args);
	return (flags->count);
}
