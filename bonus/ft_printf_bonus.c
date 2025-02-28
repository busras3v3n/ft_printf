#include <stdio.h>
#include "ft_printf_bonus.h"

#include "../libft/libft.h"
#include <stdarg.h>

static int	ft_handleformat(int i, const char *s, va_list *args)
{
	int	c;
	int	count;

	c = i + 1;
	count = 0;
	while(1)
	{
		if()
	}
}

void	reset_flags(t_flags *flags)
{
	flags->left_justify = 0;
	flags->space_sign = 0;
	flags->hash = 0;
	flags->padding_type = 0;
	flags->padding_place = 0;
	flags->padding_number = 0;
	flags->precision_place = 0;
	flags->precision_number = 0;
	flags->var_type = 'n';
	flags->len = 0;
}
int	handle_print(const char *s, va_list *args, t_flags *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_handleformat(i, s, args);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
			i++;
		}
	}
	return(count);
}
int	ft_printf(const char *s, ...)
{
	int		count;
	t_flags	*flags;
	va_list	args;

	va_start(args, s);
	flags = ft_calloc(1, sizeof(t_flags));
	reset_flags(flags);
	count = handle_print(s, &args, flags);
	va_end(args);
	return (count);
}
