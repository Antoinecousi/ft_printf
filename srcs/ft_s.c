/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:10:48 by acousini          #+#    #+#             */
/*   Updated: 2021/03/16 12:30:00 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		printprec(t_coor *cdn, int *tot, char *my_arg, int copy)
{
	while (!cdn->min && cdn->l-- > cdn->r)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
	while (cdn->r-- > 0 && *my_arg)
		write(1, &(*my_arg++), 1) && (*tot)++;
	while (cdn->min && cdn->l-- > copy)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
}

void			ft_s(t_coor *cdn, va_list ptrarg, int *tot)
{
	char		*my_arg;

	my_arg = (char*)va_arg(ptrarg, char*);
	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	if (my_arg == NULL)
		my_arg = "(null)";
	if (cdn->r > ft_strlen(my_arg) || !cdn->p)
		cdn->r = ft_strlen(my_arg);
	printprec(cdn, tot, my_arg, cdn->r);
}
