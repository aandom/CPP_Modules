# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 09:09:32 by aandom            #+#    #+#              #
#    Updated: 2023/10/23 09:09:32 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = PmergeMe.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		 $(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

rbig: 
	./$(NAME) `jot -r 3000 1 1000 | tr '\n' ' '`

rmedium: 
	./$(NAME) `jot -r 300 1 1000 | tr '\n' ' '`

rsmall: 
	./$(NAME) `jot -r 10 1 100 | tr '\n' ' '`

sbig: 
	./$(NAME) `jot 3000 1 1000 | tr '\n' ' '`

smedium:
	./$(NAME) `jot 300 1 1000 | tr '\n' ' '`

ssmall: 
	./$(NAME) `jot 10 1 100 | tr '\n' ' '`

randomval: 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) `shuf -i 1-1000 -n 3000 | tr "\n" " "`

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean re