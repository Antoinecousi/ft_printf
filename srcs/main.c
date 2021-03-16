/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:10:55 by acousini          #+#    #+#             */
/*   Updated: 2021/03/16 12:36:00 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		main()
{
	int	toto = -13;
	int	t = 5;
	int	tt = 5;
	int		b = ft_printf("|%p|", &toto);
	printf("\n%d\n", b - 2);
	printf("|%p|", &toto);
//	int		c = ft_printf("|%5.p|", NULL);
//	printf("\n%d\n", b - 2);
//	printf("|%5.p|\n", NULL);
//	printf("|%p|", ft_itox(toto, "0123456789abcdef", prec));
	system("leaks a.out");
	return (1);
}
