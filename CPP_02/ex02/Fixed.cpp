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

Fixed::Fixed( int const num ) : _fixedNnum (num << _fBits){
    std::cerr << CYAN "Int constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed( float const num ) : _fixedNnum ( roundf( num  * ( 1 << _fBits)) ){
    std::cerr << CYAN "Float constructor called." RESET << std::endl;
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

void    Fixed::setRawBits( int  const raw ) {
    std::cerr << BLUE "setRawBit member function called." RESET << std::endl;
    this->_fixedNnum = raw;
    return ;
}

float   Fixed::toFloat( void ) const {
    return ( (float)this->_fixedNnum/ (1 << _fBits) );
}

int		Fixed::toInt( void ) const
{
	return ( this->_fixedNnum >> Fixed::_fBits );	
}


Fixed & Fixed::min( Fixed & srcOnLeft, Fixed & srcOnRight) {
    if ( srcOnLeft <= srcOnRight )
        return (srcOnLeft);
    return (srcOnRight);
}

Fixed & Fixed::max( Fixed & srcOnLeft, Fixed & srcOnRight) {
    if ( srcOnLeft <= srcOnRight )
        return (srcOnRight);
    return (srcOnLeft);
}

Fixed const & Fixed::min( Fixed const & srcOnLeft, Fixed  const & srcOnRight) {
    if ( srcOnLeft <= srcOnRight )
        return (srcOnLeft);
    return (srcOnRight);
}

Fixed const & Fixed::max( Fixed const & srcOnLeft, Fixed const & srcOnRight) {
    if ( srcOnLeft <= srcOnRight )
        return (srcOnRight);
    return (srcOnLeft);
}


std::ostream& operator<<(std::ostream& os, const Fixed& num) {
    os << num.toFloat();
    return os;
}