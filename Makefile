##
## Makefile for sbml in /home/benoit.pingris/delivery/SBMLparser
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Mon Jun 12 09:54:15 2017 benoit pingris
## Last update Wed Jun 14 15:01:00 2017 benoit pingris
##

CC	=	gcc

NAME	=	SBMLparser

SRC	=	srcs/id.c				\
		srcs/reac.c				\
		srcs/free.c				\
		srcs/find.c				\
		srcs/main.c				\
		srcs/parser.c				\
		srcs/search.c				\
		srcs/flag_i.c				\
		srcs/sorting.c				\
		srcs/species.c				\
		srcs/get_info.c				\
		srcs/equation.c				\
		srcs/useful/format.c			\
		srcs/list_reaction.c			\
		srcs/useful/revstr.c			\
		srcs/useful/showtab.c			\
		srcs/useful/str_tab.c			\
		srcs/useful/my_putstr.c			\
		srcs/useful/my_strlen.c			\
		srcs/useful/my_strcmp.c			\
		srcs/gnl/get_next_line.c		\
                srcs/my_printf/my_func1.c		\
                srcs/my_printf/my_func2.c		\
                srcs/my_printf/my_func3.c		\
                srcs/my_printf/my_func4.c		\
                srcs/my_printf/my_printf.c		\
                srcs/my_printf/func_printf_1.c		\
                srcs/my_printf/func_printf_2.c 		\
                srcs/my_printf/my_basics_funcs.c	\
                srcs/my_printf/my_basics_funcs_2.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -Wextra -Wall -Werror

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

