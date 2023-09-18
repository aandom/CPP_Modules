/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:23:17 by aandom            #+#    #+#             */
/*   Updated: 2023/09/14 07:23:17 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("Uknown_Animal") {
    std::cout << "Animal default constructor called." << std::endl;
    return ;
}

// Animal::Animal(std::string const type) : _type(type) {
//     std::cout << "Animal parameterized constructor called." << std::endl;
//     return ;
// }

Animal::Animal(Animal const & src) {
    *this = src;
    std::cout << "Animal copy constructor called." << std::endl;
    return ;
}

Animal::~Animal(void) {
    std::cout << "Animal Destructor called." << std::endl;
    return ;
}

Animal  & Animal::operator=(Animal const & src) {
    if ( this != &src) {
        this->_type = src._type;
    }
    std::cout << "Animal assignment overload operator called." << std::endl;
    return(*this);
}

// std::string const &	Animal::getType(void) const {
// 	return (this->_type);
// }

void    Animal::makeSound(void) const {
	std::cout << this->_type << " : * is Making sound *" << std::endl;
	return ;
}