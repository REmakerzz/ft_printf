# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dylyk <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 17:44:21 by dylyk             #+#    #+#              #
#    Updated: 2020/12/29 16:57:16 by dylyk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= ft_itoa_base.c ft_parse_flags.c ft_parse_precision.c ft_printf.c\
				ft_putchar.c ft_putspace.c ft_putstr.c ft_putzero.c ft_strlen.c\
				ft_typeprint_c.c ft_typeprint_d_i.c ft_typeprint_p.c \
				ft_typeprint_s.c ft_typeprint_u.c ft_typeprint_xx.c ft_boxinit.c
OBJS		= $(SRC:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS) ft_printf.h
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
