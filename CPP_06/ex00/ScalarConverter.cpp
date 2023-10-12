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


int const ScalarConverter::MAXINT   = std::numeric_limits<int>::max() ;
int const ScalarConverter::MININT   = std::numeric_limits<int>::min() ;
// int const ScalarConverter::MAXFLOAT = std::numeric_limits<float>::max() ;
// int const ScalarConverter::MINFLOAT = std::numeric_limits<float>::min() ;
int const ScalarConverter::MAXCHAR  = std::numeric_limits<char>::max() ;
int const ScalarConverter::MINCHAR  = std::numeric_limits<char>::min() ;

 int ScalarConverter::INTOVERLOW = 0;
//  int FLOATOVERLOW;
//  int DOUBLEOVERLOW;
 int ScalarConverter::CHAROVERLOW = 0;
 int ScalarConverter::CHAR_NONPRINT = 0;


ScalarConverter::ScalarConverter(std::string const & input) : _type(DEF),
                                                        _intform(0),
                                                        _floatform(0),
                                                        _doubleform(0), 
                                                        _charform(0) {
    this->_converter(input);
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _type(src._type),
                                                                _intform(src._intform),
                                                                _floatform(src._floatform),
                                                                _doubleform(src._doubleform), 
                                                                _charform(src._charform) {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
    
    this->_type = src._type;
    this->_intform = src._intform;
    this->_floatform = src._floatform;
    this->_doubleform = src._doubleform;
    this->_charform = src._charform;

    return (*this);
}

char	ScalarConverter::getChar(void) const {
	return (this->_charform);
}
int	ScalarConverter::getInt(void) const {
	return (this->_intform);
}

float	ScalarConverter::getFloat(void) const {
	return (this->_floatform);
}

double	ScalarConverter::getDouble(void) const {
	return (this->_doubleform);
}


const char *	ScalarConverter::NotAStrLiteralException::what(void) const throw()
{
	return ("Error: input is different from char/int/float/double.");
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
    this->_intform = static_cast<int>(nbr);
    if (this->_intform > MAXCHAR || this->_intform < MINCHAR)
        this->CHAROVERLOW = 1;
    return (true);

}

bool    ScalarConverter::_checkFloat(std::string const & input) {
    char *endptr;
    float nbr = std::strtof(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != 'f')
        return (false);
    if (*endptr == 'f' && (endptr + 1 && *(endptr + 1) != '\0'))
        return (false);
    this->_floatform = nbr;
    if (this->_floatform > MAXCHAR || this->_floatform < MINCHAR)
        this->CHAROVERLOW = 1;
    if (this->_floatform > MAXINT || this->_floatform < MININT)
        this->INTOVERLOW = 1;
    return (true);

}

bool    ScalarConverter::_checkDouble(std::string const & input) {
    char *endptr;
    double nbr;
    size_t dotIdx;

    dotIdx = input.find('.');
    if (dotIdx == std::string::npos)
        return (false);
    nbr = std::strtod(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    this->_doubleform = nbr;
    if (this->_doubleform > MAXCHAR || this->_doubleform < MINCHAR)
        this->CHAROVERLOW = 1;
    if (this->_doubleform > MAXINT || this->_doubleform < MININT)
        this->INTOVERLOW = 1;
    return (true);

}


bool    ScalarConverter::_checkChar(std::string const & input) {
    
    if (input.length() == 1) {
        this->_charform = input[0];
        if (!std::isprint(input[0]))
            CHAROVERLOW = 1;
        return (true);
    }
    return (false);
}

bool	ScalarConverter::_checkNotaNum(std::string const & input)
{
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
	{
		INTOVERLOW = 1;
		CHAROVERLOW = 1;
		this->_floatform = std::numeric_limits<float>::infinity();
		this->_doubleform = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "-inf" || input == "-inff")
	{
		INTOVERLOW = 1;
		CHAROVERLOW = 1;
		this->_floatform = (-1) * std::numeric_limits<float>::infinity();
		this->_doubleform = (-1) * std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "nan" || input == "nanf")
	{
		INTOVERLOW = 1;
		CHAROVERLOW = 1;
		this->_floatform = std::numeric_limits<float>::quiet_NaN();
		this->_doubleform = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	return (false);
}


void    ScalarConverter::_identifyType(std::string const & input) {

    if (this->_checkInt(input))
        this->_type = INT;
    else if (this->_checkFloat(input))
        this->_type = FLOAT;
    else if (this->_checkDouble(input))
        this->_type = DOUBLE;
    else if (this->_checkChar(input))
        this->_type = CHAR;
    else if (this->_checkNotaNum(input))
        this->_type = NOTNUM;
    return ;
}

void    ScalarConverter::_castFromInt() {
	this->_floatform = static_cast<float>(this->_intform);
	this->_doubleform = static_cast<double>(this->_intform);
	this->_charform = static_cast<char>(this->_intform);
	if (!std::isprint(this->_charform))
		this->CHAR_NONPRINT = 1;
}
void    ScalarConverter::_castFromFloat() {
	this->_intform = static_cast<int>(this->_floatform);
	this->_doubleform = static_cast<double>(this->_floatform);
	this->_charform = static_cast<char>(this->_floatform);
	if (!std::isprint(this->_charform))
		this->CHAR_NONPRINT = 1;
}
void    ScalarConverter::_castFromDouble() {
	this->_floatform = static_cast<float>(this->_doubleform);
	this->_intform = static_cast<int>(this->_doubleform);
	this->_charform = static_cast<char>(this->_doubleform);
	if (!std::isprint(this->_charform))
		this->CHAR_NONPRINT = 1;
}
void    ScalarConverter::_castFromChar() {
	this->_floatform = static_cast<float>(this->_charform);
	this->_doubleform = static_cast<double>(this->_charform);
	this->_intform = static_cast<int>(this->_charform);
}

void    ScalarConverter::_converter(std::string const & input) {
    
    this->_identifyType(input);
    switch (this->_type)
	{
		case INT:
			this->_castFromInt();
			break;
		case FLOAT:
			this->_castFromFloat();
			break;
		case DOUBLE:
			this->_castFromDouble();
			break;
		case CHAR:
			this->_castFromChar();
			break;
		case NOTNUM:
			break;
		default:
			throw(ScalarConverter::NotAStrLiteralException());
	}

}

void    ScalarConverter::printChar() const {
	if (this->CHAROVERLOW)
        std::cout << "impossible";
    else if (this->CHAR_NONPRINT)
        std::cout << "Non displayable";
	else
		std::cout << this->getChar();
}

void    ScalarConverter::printInt() const {
	if (this->INTOVERLOW)
        std::cout << "impossible";
	else
		std::cout << this->getInt();
}
void    ScalarConverter::printFloat() const {
    if (this->getFloat() == static_cast<int>(this->getFloat()))
        std::cout << std::fixed << std::setprecision(1) << this->getFloat() << "f";
    else
        std::cout << this->getFloat() << "f";
}

void    ScalarConverter::printDouble() const {
    std::cout << this->getDouble();
}





std::ostream &	operator<<(std::ostream &os, ScalarConverter const &src)
{
    os << "\t- char\t: "; src.printChar();
    os << "\n \t- int\t: "; src.printInt();
    os << "\n\t- float\t: "; src.printFloat();
    os << "\n\t- double: "; src.printDouble();
	return (os);
}

