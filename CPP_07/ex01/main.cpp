/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:28:42 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 14:28:42 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void )
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: " << std::endl;
    iter(arr1, 5, &printelement);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\narr2: " << std::endl;
    iter(arr2, 5, &printelement);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: " << std::endl;
    iter(arr3, 5, &printelement);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: " << std::endl;
    iter(arr4, 5, &printelement);

    return 0;
}




// class Awesome
// {
//     public:
//         Awesome( void ): _n( 42 ) { return; }
//         Awesome( int n ): _n( n ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

// template<typename T >
// void print( T const & x) { std::cout << " " << x  << std::endl; return; }

// int main() {
//     int tab[] = { 0, 1, 2, 3, 4};
//     Awesome tab2[5];
//     Awesome tab3[4] = { Awesome(40),  Awesome(41),  Awesome(42),  Awesome(43)};
//     std::cout << "ARR_1 = \n[ \n"; iter(tab, 5, print); std::cout << "]\n" << std::endl;
//     std::cout << "ARR_2 = \n[ \n"; iter(tab2, 5, print); std::cout<< "]\n" << std::endl;
//     std::cout << "ARR_3 = \n[ \n"; iter(tab3, 4, print); std::cout << "]\n" << std::endl;
//     // iter(tab2, 5, print);
//     // iter(tab3, 4, print);
//     return 0;
// }