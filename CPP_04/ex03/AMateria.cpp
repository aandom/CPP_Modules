/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:19:11 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 04:19:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {
    std::cout << "AMateria default Constructor called." << std::endl;
    return ;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria Parameterized Constructor called." << std::endl;
    return ;
}

AMateria::AMateria(AMateria const & src) : _type(src._type) {
    std::cout << "AMateria Copy Constructor called." << std::endl;
    return ;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called." << std::endl;
	return ;
}

AMateria & AMateria::operator=(AMateria const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    std::cout << "AMateria Assignment operator overload called." << std::endl;
	return (*this);
}

// Amateria::clone;

// Amateria::use;
void        AMateria::use(ICharacter & target) {
	std::cout << "* Default materia used on " << target.getName() << " *" << std::endl;
}


std::string const &	AMateria::getType(void) const {
	return (this->_type);
}