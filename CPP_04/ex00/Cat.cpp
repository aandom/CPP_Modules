/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:51:50 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 05:51:50 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << BLUE << "Cat default constructor called." << RESET << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::Cat(Cat const & src) : Animal() {
    std::cout << BLUE << "Cat Copy constructor called." << RESET << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void) {
    std::cout << BLUE << "Cat Destructor called." << RESET << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    std::cout << BLUE << "Cat assignment overload operator called." << RESET << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << BLUE << this->_type << " : is making sound : Meoww Meoww...." << RESET << std::endl; 
    return ;
}


