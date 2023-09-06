# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 21:04:49 by aandom            #+#    #+#              #
#    Updated: 2023/08/28 21:04:49 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BankInfo

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98



$(NAME): $(OBJ)
		 $(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean re