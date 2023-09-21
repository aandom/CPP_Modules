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

Dog::Dog(void) : Animal(), _brain(new Brain()) {
    std::cout << GREEN << "Dog default constructor called." << RESET << std::endl;
    this->_type = "Dog";
    return ;
}

Dog::Dog(Dog const & src) : Animal(), _brain(NULL) {
    std::cout << GREEN << "Dog Copy constructor called." << RESET << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void) {
    std::cout << GREEN << "Dog Destructor called." << RESET << std::endl;
    delete this->_brain;
    return ;
}

Dog & Dog::operator=(Dog const & src) {
    std::cout << GREEN << "Dog assignment overload operator called." << RESET << std::endl;
    if (this != &src) {
        this->_type = src._type;
        if (this->_brain != NULL) {
            delete this->_brain;
        }
        this->_brain = new Brain(*src._brain);
    }
    return (*this);
}

void    Dog::makeSound(void) const {
    std::cout << GREEN << this->_type << " : is making sound : Woof Woof......" << RESET << std::endl;
    return ;
}

Brain * Dog::getBrain(void) const {
    return (this->_brain);
}


