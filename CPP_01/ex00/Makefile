# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 02:40:28 by aandom            #+#    #+#              #
#    Updated: 2023/08/29 02:40:28 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
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