# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaribel <amaribel@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:18:22 by amaribel          #+#    #+#              #
#    Updated: 2021/10/31 17:03:18 by amaribel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			put_hex.c \
			conversion.c \

HEADER	=	ft_printf.h

OBJS	=	${SRCS:.c=.o}

CC		=	GCC

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

.PHONY: all clean fclean re

all: ${NAME}

${NAME}:	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

.c : .o 	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean:		
			rm -f ${OBJS} 

fclean: 	clean
			${RM} ${NAME}

re:		fclean all
