/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:19:51 by aandom            #+#    #+#             */
/*   Updated: 2023/10/27 16:18:53 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ) : _arrsize( n ) {
}

Span::Span(Span const & src) { 
    *this = src;
}

Span::~Span(){
}

Span & Span::operator=(Span const & src) {
    if ( this != &src) {
        this->_arrsize = src._arrsize;
        this->_array = src._array;
    }
    return (*this);
}

const std::list<int> &  Span::getArray() const {
    return (this->_array);
}

void    Span::addNumber(int n) {
    if (this->_arrsize > this->_array.size())
        this->_array.push_back(n);
    else
        throw std::out_of_range(YELLOW "Cannot add a number: list is full" RESET);
    
}

void    Span::addNumber(std::list<int>::const_iterator itbegin, std::list<int>::const_iterator itend) {
    if (this->_arrsize <= this->_array.size())
         throw std::out_of_range( YELLOW "Cannot add a number: list is full" RESET );
    if (std::abs(std::distance(itbegin, itend)) > (int) (this->_arrsize - this->_array.size())) {
        std::string  errmsg = YELLOW "Error: Insufficient space to hold " + std::to_string(std::abs(std::distance(itbegin, itend))) + " more elements" RESET;
        throw std::out_of_range( errmsg );
    }
    if (this->_arrsize > this->_array.size()) 
        this->_array.insert(this->_array.end(), itbegin, itend);
}

unsigned int Span::shortestSpan() const {
    unsigned int	shortest;
	if (this->_array.size() < 2)
		throw (std::range_error( YELLOW "Cannot compute Shortest Span : Insufficient number of Elements / Small List Size" RESET));
    std::list<int> sorted(this->_array);
    sorted.sort();
	std::list<int>	difference(sorted);
	std::adjacent_difference(sorted.begin(), sorted.end(), difference.begin());
	shortest = *std::min_element(++difference.begin(), difference.end());
	return (shortest);
}

unsigned int Span::longestSpan() const {
    std::list<int> sorted;
    sorted = this->_array;

	if (this->_array.size() < 2)
		throw (std::range_error(YELLOW "Cannot compute Shortest Span : Insufficient number of Elements / Small List Size" RESET));
    return(*std::max_element(this->_array.begin(), this->_array.end()) - *std::min_element(this->_array.begin(), this->_array.end()));
}

std::ostream &	operator<<(std::ostream &os, std::list<int> const  &obj) {
    std::cout << "[ ";
    for (std::list<int>::const_iterator it = obj.begin();
			it != obj.end(); ++it)
		std::cout << *it << " ";
    std::cout << "]";
    return (os);
}

std::ostream &	operator<<(std::ostream &os,  Span const &obj) {
	std::cout << obj.getArray();
    return (os);
}