#include <stdio.h>
#include "ft_printf_bonus.h"

#include "../libft/libft.h"
#include <stdarg.h>

int	is_valid_flag(char c, char *flags)
{
	int	i;

	i = 0;
	while(flags[i])
	{
		if(c == flags[i])
			return(1);
		i++;
	}
	return(0);
}

void	ft_handleflags(const char *s, va_list *args, t_flags *flags)
{
	while(s[flags->i])
	{
		if(!is_valid_flag(s[flags->i], flags->valid))
			//error
		else if(is_valid_flag(s[flags->i], "cspdiuxX%"))
		{
			//print
			//reset flags
			return;
		}
		else if(s[flags->i] == '.')
		{
			flags->valid = "cspdiuxX%";
			//find precision number
		}
		else if(s[flags->i] != '0' && ft_isdigit(s[flags->i]))
		{
			flags->valid  = "cspdiuxX%.";
			//find width number
		}
	}
	//error because couldnt print anything
}

void	reset_flags(t_flags *flags)
{
	flags->left_justify = 0;
	flags->space_flag = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->padding_number = 0;
	flags->precision_number = 0;
	flags->var_type = 0;
	flags->valid = "cspdiuxX%0-+ #.";
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
