/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:09:44 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:09:44 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << GREEN << "Dog default constructor called." << RESET << std::endl;
    this->_type = "Dog";
    return ;
}

Dog::Dog(Dog const & src) : Animal() {
    std::cout << GREEN << "Dog Copy constructor called." << RESET << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void) {
    std::cout << GREEN << "Dog Destructor called." << RESET << std::endl;
    return ;
}

Dog & Dog::operator=(Dog const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    std::cout << GREEN << "Dog assignment overload operator called." << RESET << std::endl;
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << GREEN << this->_type << " : is making sound : Woof Woof......" << RESET << std::endl; 
    return ;
}


