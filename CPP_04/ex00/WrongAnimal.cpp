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
    std::cout << CYAN << "WrongAnimal default constructor called." << RESET << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type) {
    std::cout << CYAN << "WrongAnimal parameterized constructor called." << RESET << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
    *this = src;
    std::cout << CYAN << "WrongAnimal copy constructor called." << RESET << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << CYAN << "WrongAnimal default Destructor called." << RESET << std::endl;
    return ;
}

WrongAnimal  & WrongAnimal::operator=(WrongAnimal const & src) {
    if ( this != &src) {
        this->_type = src._type;
    }
    std::cout << CYAN << "WrongAnimal assignment overload operator called." << RESET << std::endl;
    return(*this);
}

std::string const &	WrongAnimal::getType(void) const {
	return (this->_type);
}

void    WrongAnimal::makeSound(void) const {
	std::cout << CYAN << this->_type << ": * is Making WrongAnimal's default sound*" << RESET << std::endl;
	return ;
}