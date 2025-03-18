# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 10:55:22 by busseven          #+#    #+#              #
#    Updated: 2025/03/18 11:40:54 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_hex.c ft_print_ptr.c ft_print_unbr.c ft_print_percent.c
BONUS_SRC	= ft_printf_bonus.c flag_utils_bonus.c \
			print_bonus.c utils_bonus.c ft_print_char.c ft_print_str.c \
			ft_print_nbr.c ft_print_hex.c ft_print_ptr.c ft_print_unbr.c ft_print_percent.c \
			arglen_bonus.c arglen_utils_bonus.c print_flags_bonus.c print_precision_bonus.c \
			print_value_utils_bonus.c
OBJS 		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)

NAME 		= libftprintf.a
LIBFT 		= ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C ./libft all 

%.o: %.c
	cc -c -Wall -Wextra -Werror $< -o $@

bonus: $(LIBFT) $(BONUS_OBJS) $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(BONUS_OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean

re: fclean all

.PHONY: all clean fclean re