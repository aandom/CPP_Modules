/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:03:04 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 14:03:04 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP



#include <iostream>

template< typename T >
void    swap( T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;

    // a = a ^ b;
    // b = b ^ a;
    // a = a ^ b;
}

template< typename T >
T       min( T& a, T& b ) {
    return ( a <= b ? a : b );
}

template< typename T >
T       max( T& a, T& b ) {
    return ( a >= b ? a : b );
}


# endif