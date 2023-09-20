/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:25:00 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:25:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "WrongCat default constructor called." << std::endl;
    this->_type = "WrongCat";
    return ;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal() {
    std::cout << "WrongCat Copy constructor called." << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat Destructor called." << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    std::cout << "WrongCat assignment overload operator called." << std::endl;
    return (*this);
}

void    WrongCat::makeSound(void) const {
    std::cout << this->_type << " : is making sound : Meow Meow...." << std::endl; 
    return ;
}


