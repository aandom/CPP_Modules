/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:19:51 by aandom            #+#    #+#             */
/*   Updated: 2023/10/17 17:36:38 by aandom           ###   ########.fr       */
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
        throw std::out_of_range("Cannot add a number: list is full");
    
}

std::ostream &	operator<<(std::ostream &os, std::list<int> const  &obj)
{
    std::cout << "[ ";
    for (std::list<int>::const_iterator it = obj.begin();
			it != obj.end(); ++it)
		std::cout << *it << " ";
    std::cout << "]";
    return (os);
}

std::ostream &	operator<<(std::ostream &os,  Span const &obj)
{
	std::cout << obj.getArray();
    return (os);
}

unsigned int Span::shortestSpan() const {
    unsigned int	shortest;
	if (this->_array.size() < 2)
		throw (std::range_error("Cann't compute Shortest Span: small list size"));
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
		throw (std::range_error("Cann't compute longest Span: small list size"));
    return(*std::max_element(this->_array.begin(), this->_array.end()) - *std::min_element(this->_array.begin(), this->_array.end()));
}
