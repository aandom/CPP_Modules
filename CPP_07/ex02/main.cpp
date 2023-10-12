/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:37 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 15:59:37 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
# define SIZE 10

int main( void )
{
    std::cout << "-----------------------------------------------------" << std::endl;

    Array<float> test;

    Array<float> intArray( SIZE );
    Array<float> intArray2( SIZE - 5 );

    for ( unsigned int i = 0; i < intArray.getSize(); i++ )
        intArray[i] = i * 2.0;

    std::cout << "Int Array 1: " << intArray << std::endl;

    intArray2 = intArray;

    std::cout << "int Array 2: " << intArray2 << std::endl;

    try {
        std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
        std::cout << "Accessing an invalid index: " << intArray[SIZE] << std::endl;
    } catch ( std::exception& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------------------------" << std::endl;

    return ( 0 );
}