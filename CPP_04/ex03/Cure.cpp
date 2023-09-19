/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:38:32 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 10:38:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure default Constructor called." << std::endl;
    return ;
}

Cure::Cure(Cure const & src) : AMateria("cure") {
    std::cout << "Cure Copy Constructor called." << std::endl;
    *this = src;
    return ;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called." << std::endl;
	return ;
}

Cure & Cure::operator=(Cure const & src) {
    this->_type = src._type;
    std::cout << "Cure Assignment operator overload called." << std::endl;
	return (*this);
}

// Cure::clone;
 AMateria * Cure::clone() const {
	AMateria * result = new Cure();
    return (result);
}

// Cure::use;
void        Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
