/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:37:30 by aandom            #+#    #+#             */
/*   Updated: 2023/08/30 05:37:30 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#define BLUE "\e[34m"

Fixed::Fixed( void ) : _fixedNnum (0){
    std::cerr << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed ( Fixed const & src) {
    std::cerr << CYAN "Copy constructor called." RESET << std::endl;
    *this = src;
	return ;
}

Fixed::~Fixed( void) {
    std::cerr << GREEN "Destructor called." RESET << std::endl;
	return ;
}

Fixed   & Fixed::operator=( Fixed const & src) {
    std::cerr << YELLOW "Copy assignment operator called." RESET << std::endl;
    if(this != &src) {
        this->_fixedNnum = src.getRawBits();
    }
	return ( *this) ;
}



int Fixed::getRawBits( void ) const {
    std::cerr << BLUE "getRawBits member function called." RESET << std::endl;
    return (this->_fixedNnum);
}


void    setRawBits( int const raw );

void    Fixed::setRawBits( int  const raw ) {
    std::cerr << BLUE "setRawBit member function called." RESET << std::endl;
    this->_fixedNnum = raw;
    return ;
}