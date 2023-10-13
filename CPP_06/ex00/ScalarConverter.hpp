/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:39:56 by aandom            #+#    #+#             */
/*   Updated: 2023/10/13 03:30:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCLALARCONVERTER_HPP
# define SCLALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <exception>
#include <iomanip>
# include <cctype>

#define RESET "\e[0m"
#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

enum    e_type 
{
    DEF = 0,
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    NOTNUM  
};

class ScalarConverter
{
    public:
        static int const MAXINT;
        static int const MININT;
        static int const MAXCHAR;
        static int const MINCHAR;
        
        static int INTOVERLOW;
        static int CHAR_NONPRINT;
        static int CHAROVERLOW;

        static int     _type;
        static int     _intform;
        static float   _floatform;
        static double  _doubleform;
        static char    _charform;
        
        static void converter(std::string const & input);

        static void    printChar();
        static void    printInt();
        static void    printFloat();
        static void    printDouble();
        
        
		class	NotAStrLiteralException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

        
        static void    _identifyType(std::string const & input);
        static bool    _checkInt(std::string const & input);
        static bool    _checkFloat(std::string const & input);
        static bool    _checkDouble(std::string const & input);
        static bool    _checkChar(std::string const & input);
        static bool    _checkNotaNum(std::string const & input);
        static void    _castFromInt();
        static void    _castFromFloat();
        static void    _castFromDouble();
        static void    _castFromChar();
        
    private:
        
        ScalarConverter();
        ScalarConverter(std::string const & input);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();

        ScalarConverter & operator=(ScalarConverter const & src);

};

// std::ostream &	operator<<(std::ostream & out, ScalarConverter const & src);

# endif