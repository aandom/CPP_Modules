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
    std::cout << "Cat default constructor called." << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::Cat(Cat const & src) : Animal() {
    std::cout << "Cat Copy constructor called." << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called." << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    std::cout << "Cat assignment overload operator called." << std::endl;
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << this->_type << " : is making sound : Meoww Meoww...." << std::endl; 
    return ;
}


