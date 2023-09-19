/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:25:19 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:25:19 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Uknown_WrongAnimal") {
    std::cout << "WrongAnimal default constructor called." << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type) {
    std::cout << "WrongAnimal parameterized constructor called." << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
    *this = src;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal default Destructor called." << std::endl;
    return ;
}

WrongAnimal  & WrongAnimal::operator=(WrongAnimal const & src) {
    if ( this != &src) {
        this->_type = src._type;
    }
    std::cout << "WrongAnimal assignment overload operator called." << std::endl;
    return(*this);
}

std::string const &	WrongAnimal::getType(void) const {
	return (this->_type);
}

void    WrongAnimal::makeSound(void) const {
	std::cout << this->_type << ": * is Making WrongAnimal's default sound*" << std::endl;
	return ;
}