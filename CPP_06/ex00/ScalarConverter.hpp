/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:39:56 by aandom            #+#    #+#             */
/*   Updated: 2023/10/13 21:01:11 by aandom           ###   ########.fr       */
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
        static int const MAX_FLOAT;
        static int const MIN_FLOAT;
        static int const MAXCHAR;
        static int const MINCHAR;
        
        static int INTOVERLOW;
        static int CHAR_NONPRINT;
        static int CHAROVERLOW;
        static int FLOATOVERLOW;

        static int     type;
        static int     intform;
        static float   floatform;
        static double  doubleform;
        static char    charform;
        
        static void converter(std::string const & input);

        static void    printChar();
        static void    printInt();
        static void    printFloat();
        static void    printDouble();
        
        
		class	NotAStrLiteralException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
        
        static int    checkinf(std::string const & input);
        
        static void    identifyType(std::string const & input);
        static bool    checkInt(std::string const & input);
        static bool    checkFloat(std::string const & input);
        static bool    checkDouble(std::string const & input);
        static bool    checkChar(std::string const & input);
        static bool    checkNotaNum(std::string const & input);
        static void    castFromInt();
        static void    castFromFloat();
        static void    castFromDouble();
        static void    castFromChar();
        
    private:
        
        ScalarConverter();
        ScalarConverter(std::string const & input);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();

        ScalarConverter & operator=(ScalarConverter const & src);

};

// std::ostream &	operator<<(std::ostream & out, ScalarConverter const & src);

# endif