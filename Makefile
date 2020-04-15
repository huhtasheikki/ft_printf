#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 13:27:05 by hhuhtane          #+#    #+#              #
#    Updated: 2020/03/26 12:15:10 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = a.out

SRC = main.c ft_printf.c ft_parser.c ft_parser2.c ft_variables.c ft_flags.c ft_tools1.c ft_parser3.c

AFILE = libft/libft.a

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -o $(NAME) -I includes

FRAMEWORK = -o $(NAME) -I includes

LIBFTX = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(AFILE)
	@echo "READY TO GO!"

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@echo "Objects cleaned"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "Totally cleaned"

re:	fclean all
