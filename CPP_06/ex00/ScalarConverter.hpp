/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:39:56 by aandom            #+#    #+#             */
/*   Updated: 2023/10/07 17:48:57 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCLALARCONVERTER_HPP
# define SCLALARCONVERTER_HPP

#include <iostream>


class ScalarConverter
{
    public:
        ScalarConverter(std::string input);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();

        ScalarConverter & operator=(ScalarConverter const & src);
        
    private:
        ScalarConverter();
        int     _intvar;
        float   _floatvar;
        double  _doublevar;
        char    _charvar;
};

# endif