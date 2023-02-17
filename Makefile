# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 12:22:51 by dfurneau          #+#    #+#              #
#    Updated: 2023/02/17 08:34:47 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pushswap

SRCS			=	chunkz_sorting.c ft_split.c ft_atoi2.c errors.c errors2.c \
					innit.c nodes.c pushers.c pushswap.c sort.c sort2.c \
					swappers.c utils.c rotators.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus