/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:37:20 by aandom            #+#    #+#             */
/*   Updated: 2023/08/30 05:37:20 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a          =   "  << a << std::endl;
	std::cout << "++a        =   " << ++a << std::endl;
	std::cout << "a          =   " << a.toInt() << std::endl;
	std::cout << "a++        =   " << a++ << std::endl;
	std::cout << "a          =   " << a << std::endl;
	std::cout << "b          =   " << b << std::endl;
	std::cout << "max (a, b) =   " << Fixed::max( a, b ) << std::endl;
	return 0;
}