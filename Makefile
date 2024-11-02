# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busras3v3n@proton.me>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 15:03:07 by busseven          #+#    #+#              #
#    Updated: 2024/11/02 17:03:37 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ft_printf.c ft_case_char.c

OBJS = $(SRCS:.c=.o)

%.o:%.c
	cc -c -Wall -Wextra -Werror $< -o $@

$(NAME) : $(OBJS) $(LIBFT)

	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus