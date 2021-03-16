/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:08:21 by acousini          #+#    #+#             */
/*   Updated: 2021/03/15 16:12:48 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		printprec(t_coor *cdn, int *tot, char *s, int cp)
{
	int		pb;

	pb = (s[0] == '-' && cdn->l > cp && cp > ft_strlen(s));
	if (s[0] == '-' && cdn->z == 1)
		write(1, "-", 1);
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

void		ft_h(t_coor *cdn, va_list ptrarg, int *tot)
{
	char			*itoa;
	int				i;
	unsigned int	my_arg;
	char			*dest;

	i = 0;
	dest = malloc(34);
	my_arg = (unsigned int)va_arg(ptrarg, char*);
	itoa = ft_itox(my_arg, "0123456789ABCDEF", dest);
	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	if (itoa[0] == '0' && cdn->p)
		printprec(cdn, tot, "\0", cdn->r);
	else
		printprec(cdn, tot, itoa, cdn->r);
	free(itoa);
}
