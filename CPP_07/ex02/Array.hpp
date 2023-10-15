/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:39:57 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 15:39:57 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#define RESET "\e[0m"
#define YELLOW "\e[33m"


template < typename T >
class Array {
    public:
        Array(void) : _array(NULL), _arrsize(0) {};
        Array( unsigned int n ) : _array(new T[n]), _arrsize(n) {};
        Array( const Array& src ) : _array(new T[src.size()]), _arrsize(src.size()) {
            for ( unsigned int i = 0; i < this->_arrsize; i++ )
                this->_array[i] = src._array[i];
        };

        Array& operator=( const Array& src ) {
            if ( this != &src ) {
                delete [] _array;
                this->_array = new T[src.size()];
                this->_arrsize = src._arrsize;
                for ( unsigned int i = 0; i < this->_arrsize; i++ )
                    this->_array[i] = src._array[i];
            }
            return *this;
        }

        T& operator[]( unsigned int i ) const {
            if ( i >= this->_arrsize )
                throw IndexOutOfBoundsException();
            return this->_array[i];
        }

        unsigned int  size( void ) const { return this->_arrsize; }

        ~Array( void ) { delete [] this->_array; }

        class IndexOutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() { return YELLOW "Index is out of bounds" RESET ;}
        };

    private:
        T*              _array;
        unsigned int    _arrsize;
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& array ) {
    out << "[";
    for ( unsigned int i = 0 ; i < array.size(); i++ ) {
        out << array[i] ;
        if (i < array.size() - 1)
            out << ", ";
    }
    out << "]";
    return out;
}



# endif