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
}

Point::Point( float const x, float const y) : _x(x), _y(y){
}

Point::Point( Point const & src) : _x(src.get_x()), _y(src.get_y()) {
}

Point::~Point (void){
} 

Point   & Point::operator=(Point const & src) {
    (void)src;
    return (*this);
}


Fixed const &	Point::get_x( void ) const
{
	return ( this->_x );
}

Fixed const &	Point::get_y( void ) const
{
	return ( this->_y );
}