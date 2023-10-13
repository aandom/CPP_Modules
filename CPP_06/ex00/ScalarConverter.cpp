/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:11:08 by aandom            #+#    #+#             */
/*   Updated: 2023/10/08 19:11:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int const ScalarConverter::MAXINT   = std::numeric_limits<int>::max();
int const ScalarConverter::MININT   = std::numeric_limits<int>::min();
int const ScalarConverter::MAXCHAR  = std::numeric_limits<char>::max();
int const ScalarConverter::MINCHAR  = std::numeric_limits<char>::min();

 int ScalarConverter::INTOVERLOW = 0;
 int ScalarConverter::CHAROVERLOW = 0;
 int ScalarConverter::CHAR_NONPRINT = 0;

int    ScalarConverter::_type = DEF;
int    ScalarConverter::_intform = 0;
float  ScalarConverter::_floatform = 0;
double ScalarConverter::_doubleform = 0;
char   ScalarConverter::_charform = 0;

const char *	ScalarConverter::NotAStrLiteralException::what(void) const throw() {
	return ( YELLOW "Error: input is different from char/int/float/double literal." RESET);
}

bool    ScalarConverter::_checkInt(std::string const & input) {
    char *endptr;
    long nbr = std::strtol(input.c_str(), &endptr, 10);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    if (nbr > MAXINT || nbr < MININT) {
        INTOVERLOW = 1;
        return (false);
    }
    _intform = static_cast<int>(nbr);
    if (_intform > MAXCHAR || _intform < MINCHAR)
        CHAROVERLOW = 1;
    return (true);
}

bool    ScalarConverter::_checkFloat(std::string const & input) {
    char *endptr;
    float nbr = std::strtof(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != 'f')
        return (false);
    if (*endptr == 'f' && (endptr + 1 && *(endptr + 1) != '\0'))
        return (false);
    _floatform = nbr;
    if (_floatform > MAXCHAR || _floatform < MINCHAR)
        CHAROVERLOW = 1;
    if (_floatform > MAXINT || _floatform < MININT)
        INTOVERLOW = 1;
    return (true);
}

bool    ScalarConverter::_checkDouble(std::string const & input) {
    char *endptr;

    size_t dotIdx = input.find('.');
    if (dotIdx == std::string::npos)
        return (false);
    double nbr = std::strtod(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    _doubleform = nbr;
    if (_doubleform > MAXCHAR || _doubleform < MINCHAR)
        CHAROVERLOW = 1;
    if (_doubleform > MAXINT || _doubleform < MININT)
        INTOVERLOW = 1;
    return (true);
}

bool    ScalarConverter::_checkChar(std::string const & input) {
    
    if (input.length() == 1) {
        _charform = input[0];
        if (!std::isprint(input[0]))
            CHAROVERLOW = 1;
        return (true);
    }
    return (false);
}

bool	ScalarConverter::_checkNotaNum(std::string const & input) {
    if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff" || 
        input == "-inf" || input == "-inff" || input == "nan" || input == "nanf") {
        INTOVERLOW = 1;
		CHAROVERLOW = 1;
        }
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff") {
		_floatform = std::numeric_limits<float>::infinity();
		_doubleform = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "-inf" || input == "-inff") {
		_floatform = (-1) * std::numeric_limits<float>::infinity();
		_doubleform = (-1) * std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "nan" || input == "nanf") {
		_floatform = std::numeric_limits<float>::quiet_NaN();
		_doubleform = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	return (false);
}

void    ScalarConverter::_identifyType(std::string const & input) {
    if (_checkInt(input))
        _type = INT;
    else if (_checkFloat(input))
        _type = FLOAT;
    else if (_checkDouble(input))
        _type = DOUBLE;
    else if (_checkChar(input))
        _type = CHAR;
    else if (_checkNotaNum(input))
        _type = NOTNUM;
    return ;
}

void    ScalarConverter::_castFromInt() {
	_floatform = static_cast<float>(_intform);
	_doubleform = static_cast<double>(_intform);
	_charform = static_cast<char>(_intform);
	if (!std::isprint(_charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::_castFromFloat() {
	_intform = static_cast<int>(_floatform);
	_doubleform = static_cast<double>(_floatform);
	_charform = static_cast<char>(_floatform);
	if (!std::isprint(_charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::_castFromDouble() {
	_floatform = static_cast<float>(_doubleform);
	_intform = static_cast<int>(_doubleform);
	_charform = static_cast<char>(_doubleform);
	if (!std::isprint(_charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::_castFromChar() {
	_floatform = static_cast<float>(_charform);
	_doubleform = static_cast<double>(_charform);
	_intform = static_cast<int>(_charform);
}

void    ScalarConverter::converter(std::string const & input) {
    _identifyType(input);
    switch (_type)
	{
		case INT:
			_castFromInt();
			break;
		case FLOAT:
			_castFromFloat();
			break;
		case DOUBLE:
			_castFromDouble();
			break;
		case CHAR:
			_castFromChar();
			break;
		case NOTNUM:
			break;
		default:
			throw(ScalarConverter::NotAStrLiteralException());
	}
    std::cout << "\t- char\t: "; printChar();
    std::cout << "\n \t- int\t: ";  printInt();
    std::cout << "\n\t- float\t: "; printFloat();
    std::cout << "\n\t- double: " ;  printDouble();
    std::cout << std::endl;
}

void    ScalarConverter::printChar() {
	if (CHAROVERLOW)
        std::cout << "impossible";
    else if (CHAR_NONPRINT)
        std::cout << "Non displayable";
	else
		std::cout << _charform;
}

void    ScalarConverter::printInt() {
	if (INTOVERLOW)
        std::cout << "impossible";
	else
		std::cout << _intform;
}

void    ScalarConverter::printFloat() {
    if (_floatform == static_cast<int>(_floatform))
        std::cout << std::fixed << std::setprecision(1) << _floatform << "f";
    else
        std::cout << _floatform << "f";
}

void    ScalarConverter::printDouble() {
    std::cout << _doubleform;
}
