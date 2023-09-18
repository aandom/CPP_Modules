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

Cat::Cat(void) : Animal("Dog"), _brain(new Brain()) {
    std::cout << "Cat default constructor called." << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::Cat(Cat const & src) : Animal(), _brain(NULL) {
    std::cout << "Cat Copy constructor called." << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called." << std::endl;
    delete this->_brain;
    return ;
}

Cat & Cat::operator=(Cat const & src) {
    std::cout << "Cat assignment overload operator called." << std::endl;
    if (this != &src) {
        this->_type = src._type;
        if (this->_brain != NULL) {
            delete this->_brain;
        }
        this->_brain = new Brain(*src._brain);
    }
    return (*this);
}

void    Cat::makeSound(void) const {
    std::cout << this->_type << " : is making sound : Meoww Meoww...." << std::endl; 
    return ;
}

Brain * Cat::getBrain(void) const {
    return (this->_brain);
}



