# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 14:53:27 by alrodri2          #+#    #+#              #
#    Updated: 2022/10/28 16:32:29 by alrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

OBJ_DIR	= ./obj/

SRC 	= 	ft_printf.c ft_puts.c ft_putnum.c

OBJS 	= 	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

DEPS	= $(addsuffix .d, $(basename $(OBJS)))
RM 		=	rm -f

MK = mkdir -p

CFLAGS 	= 	-Wall -Wextra -Werror


INCLUDE 	= -I ./

$(OBJ_DIR)%.o: %.c Makefile
	@echo "Compilando $<"
	@$(MK) $(dir $@)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Montando $@"
	@ar rcs $(NAME) $(OBJS)
		

-include $(DEPS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

