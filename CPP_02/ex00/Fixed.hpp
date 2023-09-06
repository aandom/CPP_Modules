/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:37:24 by aandom            #+#    #+#             */
/*   Updated: 2023/08/30 05:37:24 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed( void );
        Fixed( Fixed const &src );
        ~Fixed( void );
        Fixed & operator=( Fixed const &src );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:
        int _fixedNnum;
        static const int _fBits = 8;
};

# endif