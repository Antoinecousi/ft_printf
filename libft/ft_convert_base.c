/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:14:22 by acousini          #+#    #+#             */
/*   Updated: 2021/03/03 17:04:25 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_error(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' ||
				base[i] <= 32 || base[i] > 126)
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

char	*base_number_check(char *base, char *look)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (*look == base[i])
			return (i + base);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	num;
	int				neg;
	int				i;

	num = 0;
	neg = 1;
	i = 0;
	if (ft_base_error(base))
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg = neg * -1;
			i++;
		}
		while (base_number_check(base, &str[i]))
		{
			num *= ft_strlen(base);
			num += (unsigned int)(base_number_check(base, &str[i]) - base);
			i++;
		}
	}
	return (int)(num * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	char	*nb_converti;

	if (ft_base_error(base_from) == 0 || ft_base_error(base_to) == 0)
		return (0);
	nb_converti = malloc(34);
	nb_int = ft_atoi_base(nbr, base_from);
	ft_almost_itoa(nb_int, base_to, nb_converti);
	return (nb_converti);
}
