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

    Array<char> test;

    std::cout << "test: " << test << std::endl;

    Array<char> intArray( SIZE );
    Array<char> intArray2( SIZE - 5 );

    for ( unsigned int i  = 0; i < intArray.size(); i++ )
        intArray[i] = (i/2 + 40) * 2.0;

    std::cout << "Int Array 1: " << intArray << std::endl;

    intArray2 = intArray;

    std::cout << "int Array 2: " << intArray2 << std::endl;

    try {
        std::cout << "Accessing a Value via index: intArray[5] : " << intArray[5] << std::endl;
        std::cout << "Accessing a Value via invalid index: intArray[" << SIZE << "] : " 
        << intArray[SIZE] << std::endl;
    } catch ( std::exception& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------------------------" << std::endl;

    return ( 0 );
}



// class Awesome
// {
//     public:
//         Awesome(void): _n(0) { }
//         Awesome( int n): _n(n) {}
//         Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//         int get_n() const { return _n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
//     Array<Awesome> arr(5);
//     std::cout << "test: " << arr << std::endl;

//     for ( unsigned int i  = 0; i < arr.size(); i++) {
//         // Awesome * a = new Awesome(i);
//         Awesome a(i * 2);
//         arr[i] = a;
//         // delete a;
//     }

//     std::cout << "test2: " << arr << std::endl;
// }

