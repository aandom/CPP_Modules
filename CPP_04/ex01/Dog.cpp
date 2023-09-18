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

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
    std::cout << "Dog default constructor called." << std::endl;
    this->_type = "Dog";
    return ;
}

Dog::Dog(Dog const & src) : Animal(), _brain(NULL) {
    std::cout << "Dog Copy constructor called." << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called." << std::endl;
    delete this->_brain;
    return ;
}

Dog & Dog::operator=(Dog const & src) {
    std::cout << "Dog assignment overload operator called." << std::endl;
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
    std::cout << this->_type << " : is making sound : Woof Woof......" << std::endl; 
    return ;
}

Brain * Dog::getBrain(void) const {
    return (this->_brain);
}

