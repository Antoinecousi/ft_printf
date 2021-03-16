/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:57:23 by acousini          #+#    #+#             */
/*   Updated: 2021/03/15 16:33:13 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		printprec(t_coor *cdn, int *tot, char *s, int cp)
{
	int		pb;

	pb = (s[0] == '-' && cdn->l > cp && cp >= ft_strlen(s));
	if (s[0] == '-' && cdn->z == 1)
		write(1, "-", 1);
//	printf("%d\n%d\n%d\n%d\n%d\n", cdn->min, cdn->z, cdn->r, cdn->l, cdn->p);
	while (!cdn->min && cdn->l > ft_strlen(s) + pb && cdn->l-- > cdn->r + pb)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
	if (s[0] == '-' && (cdn->z == 0 || cdn->r))
		write(1, "-", 1);
	while (cdn->r-- > ft_strlen(s) - (s[0] == '-'))
		write(1, "0", 1) && (*tot)++;
	ft_putstr(s + (s[0] == '-'));
	(*tot) += ft_strlen(s);
	while (cdn->min && cdn->l > ft_strlen(s) + pb && cdn->l-- > cp + pb)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
}

void		ft_d(t_coor *cdn, va_list ptrarg, int *tot)
{
	char	*itoa;
	int		i;
	int		my_arg;

	i = 0;
	my_arg = (int)va_arg(ptrarg, int);
	itoa = ft_itoa(my_arg);
	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	if (itoa[0] == '0' && cdn->p)
		printprec(cdn, tot, "\0", cdn->r);
	else
		printprec(cdn, tot, itoa, cdn->r);
	free(itoa);
}
