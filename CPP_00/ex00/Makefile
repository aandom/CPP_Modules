# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 00:29:56 by aandom            #+#    #+#              #
#    Updated: 2023/08/20 00:29:56 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): 
		$(CC) $(CPPFLAGS) megaphone.cpp -o $(NAME)

all: $(NAME)

clean: 
		rm -f $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean re