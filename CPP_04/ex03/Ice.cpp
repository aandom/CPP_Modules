/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:53:47 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 10:53:47 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice default Constructor called." << std::endl;
    return ;
}

Ice::Ice(Ice const & src) : AMateria("ice") {
    std::cout << "Ice Copy Constructor called." << std::endl;
    *this = src;
    return ;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called." << std::endl;
	return ;
}

Ice & Ice::operator=(Ice const & src) {
    this->_type = src._type;
    std::cout << "Ice Assignment operator overload called." << std::endl;
	return (*this);
}

// Ice::clone;
 AMateria * Ice::clone() const {
	AMateria * result = new Ice();
    return (result);
}

// Ice::use;
void        Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}