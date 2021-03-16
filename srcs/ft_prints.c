/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:54:16 by acousini          #+#    #+#             */
/*   Updated: 2021/02/10 16:53:14 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_putcon(s_list *coordonees, va_list ptrarg, int *tot, char c)
{
	if (c == 'c')
		ft_c(&coordonees, ptrarg, &tot, c);
	if (c == 's')
		ft_s(&coordonees, ptrarg, &tot, c);
	if (c == 'p')
		ft_p(&coordonees, ptrarg, &tot, c);
	if (c == 'd')
		ft_d(&coordonees, ptrarg, &tot, c);
	if (c == 'i')
		ft_i(&coordonees, ptrarg, &tot, c);
	if (c == 'u')
		ft_u(&coordonees, ptrarg, &tot, c);
	if (c == 'x')
		ft_x(&coordonees, ptrarg, &tot, c);
	if (c == 'X')
		ft_h(&coordonees, ptrarg, &tot, c);
	if (c == '%')
		ft_A(&coordonees, ptrarg, &tot, c);
}

static void	ft_puterror(char *str, int *tot, int *i)
{
	while (ft_strchr("0123456789-.*", str[*i]) && str[*i + 1] != '\0')
	{
		write(1, &str[*i], 1);
		(*i)++;
		(*tot)++;
	}
	(*tot)++;
	write(1, &str[*i], 1);
}
