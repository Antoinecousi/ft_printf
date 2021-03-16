/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:12:46 by acousini          #+#    #+#             */
/*   Updated: 2021/03/16 13:39:23 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*strrrev(char *str, int offset_of_center)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i + offset_of_center];
		str[i + offset_of_center] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

char	*ft_ltox(long nbr, char *base, char *nb_dest)
{
	int		len;
	long	nbr_unsigned;
	int		i;

	i = 0;
	nbr_unsigned = nbr;
	len = ft_strlen(base);
	if (nbr < 0)
		nbr_unsigned *= -1;
	if (nbr_unsigned == 0)
		nb_dest[i++] = *(base);
	while (nbr_unsigned > 0)
	{
		nb_dest[i] = *(base + (nbr_unsigned % len));
		nbr_unsigned = nbr_unsigned / len;
		i++;
	}
	nb_dest[i] = '\0';
	return ((nbr < 0) ? strrrev(nb_dest, 1) : strrrev(nb_dest, 0));
}

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
	write(1, &s[0], 1) && (*tot)++;
	write(1, &s[1], 1) && (*tot)++;;
	while (cdn->r-- > ft_strlen(s) - 2)
		write(1, "0", 1) && (*tot)++;
	ft_putstr(s + 2);
	(*tot) += ft_strlen(s + 2);
//	while (cdn->r-- > 0 && *(s + 2))
//		write(1, &(*s++), 1) && (*tot)++;
	while (cdn->min && cdn->l > ft_strlen(s) + pb && cdn->l-- > cp + pb)
		if (cdn->z)
			write(1, "0", 1) && (*tot)++;
		else
			write(1, " ", 1) && (*tot)++;
}

void		ft_p(t_coor *cdn, va_list ptrarg, int *tot)
{
	int		i;
	long	my_arg;
	char	*dest;

	i = 0;
	dest = malloc(34);
	my_arg = (long)va_arg(ptrarg, long);
	dest = ft_ltox(my_arg, "0123456789abcdef", dest);
	dest = ft_strjoin("0x", dest);
/*	if (dest)
	{
		free(dest);
		printprec(cdn, tot, "0", cdn->r);
		return  ;
	}*/
	/*if ((cdn->z && cdn->min) || (cdn->z && cdn->r))
		cdn->z = 0;
	if (dest[2] == '0')
		dest = "0x";
	if (cdn->r > ft_strlen(dest) || !cdn->p)
		cdn->r = ft_strlen(dest);
	printprec(cdn, tot, dest, cdn->r);
	*/if ((cdn->z && cdn->min) || (cdn->z && cdn->r) || cdn->p)
		cdn->z = 0;
//	if (cdn->r > ft_strlen(dest) || !cdn->p)
//		cdn->r = ft_strlen(dest);
	if (dest[2] == '0' && cdn->p)
		printprec(cdn, tot, "0x", cdn->r);
	else
		printprec(cdn, tot, dest, cdn->r);
	free(dest);
}

/*int		main()
{
	int		coucou = 1;
	char	coucou1[34];
	printf("%s\n", ft_ltox(126, "0123456789abcdef", coucou1));
}*/
