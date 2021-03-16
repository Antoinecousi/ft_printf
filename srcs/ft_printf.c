/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:10:49 by acousini          #+#    #+#             */
/*   Updated: 2021/03/16 12:25:24 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_get_size_star_prec(va_list ptrarg, int *i, const char *str)
{
	int		right;

	right = 0;
	while (ft_strchr("0-", str[*i]))
		(*i)++;
	right = ft_atoi(str + *i);
	if (right == 0 && str[*i] == '*')
	{
		right = (int)va_arg(ptrarg, int);
		(*i)++;
	}
	while (ft_strchr("0-123456789*.", str[*i]))
		(*i)++;
	return (right);
}

static int		ft_get_size_star(va_list ptrarg, int *i, const char *str)
{
	int		left;

	left = 0;
	left = ft_atoi(str + *i);
	if (left == 0 && str[*i] == '*')
	{
		left = (int)va_arg(ptrarg, int);
		(*i)++;
	}
	return (left);
}

static t_coor	*list_init(const char *str, int *i, va_list ptrarg, t_coor *coordonees)
{
	while (ft_strchr("0-", str[*i]))
	{
		if (str[*i] == '-')
			coordonees->min = 1;
		if (str[*i] == '0')
			coordonees->z = str[*i] == '0';
		(*i)++;
	}
	coordonees->l = ft_get_size_star(ptrarg, i, str);
	while (ft_strchr("0123456789-*", str[*i]))
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		coordonees->p = 1;
		coordonees->r = ft_get_size_star_prec(ptrarg, i, str);
	}
	return (coordonees);
}

static void			ft_putstr_conversion(t_coor *cdn, va_list ptrarg, int *tot_size, char c)
{
	if (cdn->l < 0)
	{
		cdn->l = -1 * (cdn->l < 0) * cdn->l;
		cdn->min = 1;
		cdn->z = 0;
	}
	if (cdn->r < 0 && cdn->z && cdn->min)
	{
		cdn->z = 1;
		cdn->min = 0;
	}
	if (cdn->r < 0)
	{
		cdn->p = 0;
		cdn->r = 0;
	}
	if (c == 'd' || c == 'i')
		ft_d(cdn, ptrarg, tot_size);
	if (c == 'p')
		ft_p(cdn, ptrarg, tot_size);
	if (c == 'o')
		ft_d(cdn, ptrarg, tot_size);
	if (c == 'X')
		ft_h(cdn, ptrarg, tot_size);
	if (c == 'x')
		ft_x(cdn, ptrarg, tot_size);
	if (c == 'u')
		ft_u(cdn, ptrarg, tot_size);
	if (c == 's')
		ft_s(cdn, ptrarg, tot_size);
	if (c == 'c')
		ft_c(cdn, ptrarg, tot_size);
	if (c == '%')
		ft_A(cdn, ptrarg, tot_size);
}

static void		ft_puterror(const char *str, int *tot_size)
{
	write(1, &*str, 1);
	str++;
	while (ft_strchr("0123456789-.*", *str))
	{
		write(1, &*str, 1);
		str++;
		(*tot_size)++;
	}
}

static int	ft_cconversion(const char *str, va_list ptrarg, t_coor *coordonees, int *tot_size)
{
	int		i;

	i = 0;
	coordonees = list_init(str, &i, ptrarg, coordonees);
	if (ft_strchr("cspdiuxX%", str[i]))
		ft_putstr_conversion(coordonees, ptrarg, tot_size, str[i]);
	else
		ft_puterror(str - 1, tot_size);
	return (i + 1);
}

t_coor		ft_init(t_coor *coordonees)
{
	coordonees->z = 0;
	coordonees->l = 0;
	coordonees->r = 0;
	coordonees->p = 0;
	coordonees->min = 0;
	return (*coordonees);
}

static int		ft_parsing(const char *str, t_coor *coordonees, va_list ptrarg)
{
	int		i;
	int		tot_size;

	i = 0;
	coordonees = malloc(sizeof(t_coor));
	tot_size = 0;
	while (str[i] && i < (int)ft_strlen(str))
	{
		if (str[i] == '%')//!!!!!!!
		{
			i++;
			*coordonees = ft_init(coordonees);
			i += ft_cconversion(str + i, ptrarg, coordonees, &tot_size);
		}
		else
			write(1, &str[i++], 1) && tot_size++;
	}
	free(coordonees);
	return (tot_size);
}

/*static int		ft_onversions(char c)
{
	char	*conversions;
	size_t	i;

	conversions = "cspdiuxX%";
	i = 0;
	while (conversions[i])
	{
		if (c == conversions[i])
			return (0);
		i++;
	}
	return (1);
}*/

/*int		ft_errors(const char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_conversions(str[i + 1]))
			return (0);
		i++;
	}
	i = 0;
	return (1);
}*/

int		ft_printf(const char *str, ...)
{
	va_list		ptrarg;
	int			i;

	va_start(ptrarg, str);
	i = ft_parsing(str, NULL, ptrarg);
	va_end(ptrarg);
	return (i);
}
