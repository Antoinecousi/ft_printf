/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:32:42 by acousini          #+#    #+#             */
/*   Updated: 2021/03/16 12:25:25 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_getsize(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_utoa(unsigned int nb)
{
	char			*str;
	unsigned int	nbr;
	int				len;

	nbr = nb;
	len = ft_getsize(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[len] = '0' + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (str);
}


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

void		ft_u(t_coor *cdn, va_list ptrarg, int *tot)
{
	char			*utoa;
	unsigned int	i;
	unsigned int	j;

	i = (unsigned int)va_arg(ptrarg, unsigned int);
	utoa = ft_utoa(i/*(unsigned int)va_arg(ptrarg, unsigned int)*/);
	if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
	if (utoa[0] == '0' && cdn->p)
		printprec(cdn, tot, "\0", cdn->r);
	else
		printprec(cdn, tot, utoa, cdn->r);
	free(utoa);
}
