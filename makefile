# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acousini <acousini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 18:00:10 by acousini          #+#    #+#              #
#    Updated: 2021/03/15 16:36:31 by acousini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	

NAME		=	libftprintf.a

SRCS		=	ft_d.c ft_h.c ft_p.c ft_u.c ft_x.c ft_printf.c ft_s.c ft_c.c \
				ft_itox.c ft_A.c ft_u.c

HEADERS		=	-I libft -I include

OBJECTS		=	${addprefix srcs/,${SRCS:.c=.o}}

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@make -C libft
				@cp libft/libft.a ${NAME}
				@ar rcs ${NAME} ${OBJECTS}

clean:
				rm -rf ${OBJECTS}
				make clean -C libft

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
