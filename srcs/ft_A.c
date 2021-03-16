/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_A.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:20:46 by acousini          #+#    #+#             */
/*   Updated: 2021/03/15 16:12:19 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		printprec(t_coor *cdn, int *tot, char my_arg)
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

void		ft_A(t_coor *cdn, va_list ptrarg, int *tot)
{
	int		reader;

	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	cdn->r = 1;
	printprec(cdn, tot, '%');
}
