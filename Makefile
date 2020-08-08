# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 18:09:10 by hhuhtane          #+#    #+#              #
#    Updated: 2020/08/08 10:41:41 by hhuhtane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a

CFILE = ft_printf.c \
		ft_initialize.c \
		ft_parse.c \
		get_variable_info.c \
		get_format_id.c \
		get_variable.c \
		ft_reset.c \
		ft_arg_convert.c \
		ft_do_flags.c \
		ft_flags_fun.c \
		ft_field_width.c \
		ft_l_modifiers.c \
		ft_lmod_fun.c \
		convert_di.c \
		ft_tools.c \
		ft_str_to_lst.c \
		ft_precision.c

OBJ = $(CFILE:.c=.o)

PRINTF_H = -I includes/
LIBFT_H = -I srcs/libft/

SRC_DIR = srcs/
OBJ_DIR = obj/
LIBFT_DIR = srcs/libft/

OFILE = $(CFILE:$%.c=%.o)
SRCS = $(addprefix $(SRC_DIR),$(CFILE))

COMPILE = gcc $(PRINTF_H) $(LIBFT_H) -c -o

CC = gcc
FLAGS = -Wall -Wextra -Werror

COLOR_RESET = \033[0m
COLOR_WAIT = \033[0;31m
COLOR_OK = \033[0;32m
COLOR_TITLE = \033[1;37m

all : $(NAME)

$(NAME):
		@echo "START BUILDING $(COLOR_TITLE)$(LIBFT_A)$(COLOR_RESET)"
		@make -C $(LIBFT_DIR) 
		@echo "COPY $(COLOR_TITLE)$(LIBFT_A)$(COLOR_RESET) to root [$(COLOR_OK) OK $(COLOR_RESET)]"
		@cp $(LIBFT_DIR)$(LIBFT_A) ./$(NAME)
		@$(CC) $(FLAGS) $(PRINTF_H) $(LIBFT_H) -c $(SRCS)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

test: fclean all
		$(CC) $(LIBFT_H) $(NAME) main.c

norm:
		@echo "Norminette $(COLOR_TITLE)$(SRC_DIR)$(COLOR_RESET)"
		norminette ./srcs
		@echo "Norminette $(COLOR_TITLE)$(LIBFT_DIR)$(COLOR_RESET)"
		norminette $(LIBFT_DIR)

fclean:
	rm $(NAME)
