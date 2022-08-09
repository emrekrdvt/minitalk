# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a <a@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 14:26:41 by a          #+#    #+#              #
#    Updated: 2022/06/13 14:26:52 by a         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_split.c ft_itoa.c ft_strlen.c ft_strjoin.c ft_printf.c yazdir.c \
					ft_substr.c ft_strdup.c ft_atoi.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
