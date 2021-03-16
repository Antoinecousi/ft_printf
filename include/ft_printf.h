/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:54:52 by acousini          #+#    #+#             */
/*   Updated: 2021/03/15 16:37:06 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_coor
{
	int				z;
	int				l;
	int				r;
	int				min;
	int				p;
}					t_coor;

int				ft_atoi(const char *str);
void			ft_d(t_coor *coordonees, va_list ptrarg, int *tot);
int				ft_printf(const char *str, ...);
void			ft_s(t_coor *coordonees, va_list ptrarg, int *tot);
void			ft_c(t_coor *coordonees, va_list ptrarg, int *tot);
char			*ft_itox(unsigned int nbr, char *base, char *nb_dest);
void			ft_x(t_coor *cdn, va_list ptrarg, int *tot);
void			ft_h(t_coor *cdn, va_list ptrarg, int *tot);
void			ft_p(t_coor *cdn, va_list ptrarg, int *tot);
void			ft_A(t_coor *cdn, va_list ptrarg, int *tot);
void			ft_u(t_coor *cdn, va_list ptrarg, int *tot);

#endif
