#include "ft_printf.h"

void	ft_handle_unsigned(unsigned int nb, struct s_val *val,
	struct s_opt *opt, const char format)
{
	char *str;

	if (nb == 0 && val->precision == 0 && opt->dot == '.')
	{
		handle_zero_zero(val, opt, format);
		val->result--;
		return ;
	}
	str = ft_unsigned_itoa(nb);
	ft_handle_nb(val, opt, 1, str);
	free(str);
	return ;
}

void	handle_zero_zero(struct s_val *val, struct s_opt *opt,
	const char format)
{
	if (format == 'p' && opt->negative)
	{
		if (opt->dot == '.')
			val->result += ft_putstr("0x", val, opt, format);
		else
			val->result += ft_putstr("0x0", val, opt, format);
	}
	while (val->width > 0)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
	if (format == 'p' && !opt->negative)
	{
		if (opt->dot == '.')
			val->result += ft_putstr("0x", val, opt, format);
		else
			val->result += ft_putstr("0x0", val, opt, format);
	}
	if (format == 'd' || format == 'i')
		val->result--;
}

char	*ft_handle_int(int nb)
{
	char	*str;
	int		neg;

	neg = 1;
	if (nb < 0)
		neg = -1;
	if (nb == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(nb * neg);
	return (str);
}

void	ft_handle_numbers(const char format, va_list tab, struct s_val *val,
	struct s_opt *opt)
{
	char	*str;
	int		neg;
	int		nb;

	neg = 1;
	if (format == 'u')
	{
		nb = va_arg(tab, unsigned int);
		ft_handle_unsigned(nb, val, opt, format);
		reset_opt(val, opt);
		return ;
	}
	nb = va_arg(tab, int);
	if (nb == 0 && val->precision == 0 && opt->dot == '.')
		handle_zero_zero(val, opt, format);
	if (format == 'u' || (nb == 0 && val->precision == 0 && opt->dot == '.'))
		return ;
	if (nb < 0)
		neg = -1;
	str = ft_handle_int(nb);
	ft_handle_nb(val, opt, neg, str);
	free(str);
	reset_opt(val, opt);
}

