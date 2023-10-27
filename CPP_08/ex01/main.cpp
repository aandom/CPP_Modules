/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:19:18 by aandom            #+#    #+#             */
/*   Updated: 2023/10/27 16:17:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <iostream>
# include <limits>

#include "Span.hpp"


void    testLongestSpan(Span const & sp) {

    try {
        std::cout << "Longest span\t: " << sp.longestSpan() << std::endl;
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}

void    testShortestSpan(Span const & sp) {

    try {
        std::cout << "Shortest span\t: " << sp.shortestSpan() << std::endl;
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}

void    testaddNum(Span & sp, int num) {

    try {
        sp.addNumber(num);
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}


int RandomNumber ( ) { return (std::rand()% INT_MAX);}

void    testAddWithRange(Span & sp, unsigned int range) {

    std::list<int> m (range);

    std::srand ( unsigned ( std::time(0) ) );
    std::generate (m.begin(), m.end(), RandomNumber);

    try {
        sp.addNumber( m.begin(), m.end());
        std::cout << BLUE "successfuly added " << std::abs(std::distance(m.begin(), m.end())) <<  " Elements " RESET << std::endl;
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}


int main( void )
{
    Span sp = Span( 5 );

    testaddNum(sp, -9);
    testaddNum(sp, 3);
    testaddNum(sp, 9);
    testaddNum(sp, 17);
    testaddNum(sp, 111);
    

    std::cout << "sp: " << sp << std::endl;
    
    testLongestSpan(sp);
    testShortestSpan(sp);

    std::cout << std::endl;

    Span span(10000);

    std::cout << "span: " << span << std::endl;
    testAddWithRange(span , 10000);
    std::cout << "span: " << span << std::endl;

    // Span span(10);

    // std::cout << "span: " << span << std::endl;
    // testAddWithRange(span , 10);
    // std::cout << "span: " << span << std::endl;

    testLongestSpan(span);
    testShortestSpan(span);

    return 0;
}