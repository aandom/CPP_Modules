# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 07:27:32 by aandom            #+#    #+#              #
#    Updated: 2023/09/11 07:27:32 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checkpoint

SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		 $(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean re