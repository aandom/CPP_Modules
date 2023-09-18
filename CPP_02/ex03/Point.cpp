/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 06:14:02 by aandom            #+#    #+#             */
/*   Updated: 2023/09/10 06:14:02 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
    // std::cout << "Point Default constructor called."  << std::endl;
    return ;
}

Point::Point( float const x, float const y) : _x(x), _y(y){
    // std::cout << "Point Parameterized constructor called."  << std::endl;
    return ;
}

Point::Point( Point const & src) : _x(src.get_x()), _y(src.get_y()) {
    // std::cout << "Point copy constructor called."  << std::endl;
    return ;
}

Point::~Point (void){
    // std::cout << "Point Destructor called." << std::endl;
    return ;
} 

Point   & Point::operator=(Point const & src) {
    // std::cout << "Point copy assignment operator overload."  << std::endl;
    (void)src;
    return (*this);
    // (Fixed) this->_x = src.get_x();
    // (Fixed) this->_y = src.get_y();
}


Fixed const &	Point::get_x( void ) const
{
	return ( this->_x );
}

Fixed const &	Point::get_y( void ) const
{
	return ( this->_y );
}