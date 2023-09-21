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
    std::cout << YELLOW << "Animal default constructor called." << RESET << std::endl;
    return ;
}

// Animal::Animal(std::string const & type) : _type(type) {
//     std::cout << YELLOW << "Animal parameterized constructor called." << RESET << std::endl;
//     return ;
// }

Animal::Animal(Animal const & src) {
    *this = src;
    std::cout << YELLOW << "Animal copy constructor called." << RESET << std::endl;
    return ;
}

Animal::~Animal(void) {
    std::cout << YELLOW << "Animal default Destructor called." << RESET << std::endl;
    return ;
}

Animal  & Animal::operator=(Animal const & src) {
    if ( this != &src) {
        this->_type = src._type;
    }
    std::cout << YELLOW << "Animal assignment overload operator called." << RESET << std::endl;
    return(*this);
}

std::string const &	Animal::getType(void) const {
	return (this->_type);
}

void    Animal::makeSound(void) const {
	std::cout << YELLOW << this->_type << " : * is Making sound *" << RESET << std::endl;
	return ;
}