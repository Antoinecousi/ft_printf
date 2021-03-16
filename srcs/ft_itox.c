/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:47 by acousini          #+#    #+#             */
/*   Updated: 2021/03/04 16:10:58 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*strrev(char *str, int offset_of_center)
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
	return (str);
}

char	*ft_itox(unsigned int nbr, char *base, char *nb_dest)
{
	unsigned int	len;
	unsigned int	nbr_unsigned;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		nb_dest[i++] = '-';
		nbr_unsigned = (unsigned int)(-1 * nbr);
	}
	else
		nbr_unsigned = (unsigned int)nbr;
	len = ft_strlen(base);
	if (nbr_unsigned == 0)
		nb_dest[i++] = *(base);
	while (nbr_unsigned > 0)
	{
		nb_dest[i] = *(base + (nbr_unsigned % len));
		nbr_unsigned = nbr_unsigned / len;
		i++;
	}
	nb_dest[i] = 0;
	return ((nbr < 0) ? strrev(nb_dest, 1) : strrev(nb_dest, 0));
}
/*
int		main()
{
	int a = -155;
	char *dest;
	dest = malloc(34);
	printf("%x\n", -1);
	printf("%s\n", ft_itox(1, "0123456789abcdef", dest));
}*/
