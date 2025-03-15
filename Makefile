# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 10:55:22 by busseven          #+#    #+#              #
#    Updated: 2025/03/15 16:33:12 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_hex.c ft_print_ptr.c ft_print_unbr.c ft_print_percent.c
BONUS_SRC	= ./bonus/ft_printf_bonus.c ./bonus/flag_utils_bonus.c \
			./bonus/print_bonus.c ./bonus/utils_bonus.c ft_print_char.c ft_print_str.c \
			ft_print_nbr.c ft_print_hex.c ft_print_ptr.c ft_print_unbr.c ft_print_percent.c \
			./bonus/arglen_bonus.c ./bonus/arglen_utils_bonus.c ./bonus/print_flags_bonus.c ./bonus/print_precision_bonus.c
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
	gcc -g -c -Wall -Wextra -Werror $< -o $@

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