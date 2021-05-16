# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 14:44:34 by cfiliber          #+#    #+#              #
#    Updated: 2021/05/11 14:46:00 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		ft_flags.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_int.c \
		ft_print_unsigned.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_print_wildcard.c \
		ft_len.c \
		ft_put.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(SRCS)
		   	ar crs $(NAME) $(OBJS)

.c.o: $(CC) $(CFLAGS)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
