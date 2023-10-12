/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:16 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 14:07:16 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main( void )
{
    int a = 42;
    int b = 43;

    std::cout << "Before_swap : "<< "a = " << a << ", b = " << b << std::endl;
    swap( a, b );
    std::cout << "After_swap  : "<< "a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

    std::string c = "42abudhabi1";
    std::string d = "42abudhabi2";

    std::cout << "Before_swap : " << "c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "After_swap  : " << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

    return 0;
}