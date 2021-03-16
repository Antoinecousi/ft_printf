/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:54:50 by acousini          #+#    #+#             */
/*   Updated: 2021/03/15 16:12:31 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		printprec(t_coor *cdn, int *tot, unsigned char my_arg)
{
	int		copy;

	copy = cdn->r;
	while (!cdn->min &&cdn->l-- > cdn->r)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
	write(1, &my_arg, 1) && (*tot)++;
	while (cdn->min && cdn->l-- > copy)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
}

void			ft_c(t_coor *cdn, va_list ptrarg, int *tot)
{
	unsigned char	my_arg;

	my_arg = (unsigned char)va_arg(ptrarg, int);
	//	if (my_arg == '\0')
	//		my_arg = ;
	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	/*	if (my_arg == '\0')
		my_arg = ' ';*/
	cdn->r = 1;
	printprec(cdn, tot, my_arg);
}
