/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:39:56 by aandom            #+#    #+#             */
/*   Updated: 2023/10/09 16:30:30 by aandom           ###   ########.fr       */
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


class ScalarConverter
{
    public:
        ScalarConverter(std::string const & input);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();

        ScalarConverter & operator=(ScalarConverter const & src);

        char    getChar() const;
        int    getInt() const;
        float    getFloat() const;
        double    getDouble() const;
        
        
		class	NotAStrLiteralException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

        static int const MAXINT;
        static int const MININT;
        static int const MAXFLOAT;
        static int const MINFLOAT;
        static int const MAXCHAR;
        static int const MINCHAR;
        
        static int INTOVERLOW;
        // static int FLOATOVERLOW;
        // static int DOUBLEOVERLOW;
        static int CHAR_NONPRINT;
        static int CHAROVERLOW;
        
    private:
        enum    e_type 
        {
            DEF = 0,
            INT,
            FLOAT,
            DOUBLE,
            CHAR,
            NOTNUM  
        };
        
        ScalarConverter();
        int     _type;
        int     _intform;
        float   _floatform;
        double  _doubleform;
        char    _charform;

        void    _identifyType(std::string const & input);
        void    _converter(std::string const & input);
        bool    _checkInt(std::string const & input);
        bool    _checkFloat(std::string const & input);
        bool    _checkDouble(std::string const & input);
        bool    _checkChar(std::string const & input);
        bool    _checkNotaNum(std::string const & input);
        void    _castFromInt();
        void    _castFromFloat();
        void    _castFromDouble();
        void    _castFromChar();
        void    _seterror();

};

std::ostream &	operator<<(std::ostream & out, ScalarConverter const & src);

# endif