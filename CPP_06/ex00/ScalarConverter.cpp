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
int const ScalarConverter::MAX_FLOAT   = std::numeric_limits<float>::max();
int const ScalarConverter::MIN_FLOAT   = std::numeric_limits<float>::min();
int const ScalarConverter::MAXCHAR  = std::numeric_limits<char>::max();
int const ScalarConverter::MINCHAR  = std::numeric_limits<char>::min();

 int ScalarConverter::INTOVERLOW = 0;
 int ScalarConverter::CHAROVERLOW = 0;
 int ScalarConverter::CHAR_NONPRINT = 0;
 int ScalarConverter::FLOATOVERLOW = 0;

int    ScalarConverter::type = DEF;
int    ScalarConverter::intform = 0;
float  ScalarConverter::floatform = 0;
double ScalarConverter::doubleform = 0;
char   ScalarConverter::charform = 0;

const char *	ScalarConverter::NotAStrLiteralException::what(void) const throw() {
	return ( YELLOW "Error: input is different from char/int/float/double literal." RESET);
}

bool    ScalarConverter::checkInt(std::string const & input) {
    char *endptr;
    long nbr = std::strtol(input.c_str(), &endptr, 10);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    if (nbr > MAXINT || nbr < MININT) {
        INTOVERLOW = 1;
        return (false);
    }
    intform = static_cast<int>(nbr);
    if (intform > MAXCHAR || intform < MINCHAR)
        CHAROVERLOW = 1;
    return (true);
}

bool    ScalarConverter::checkFloat(std::string const & input) {
    char *endptr;
    // float nbr = std::strtof(input.c_str(), &endptr);
    double nbr2 = std::strtod(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != 'f')
        return (false);
    if (*endptr == 'f' && (endptr + 1 && *(endptr + 1) != '\0'))
        return (false);
    if (checkinf(input) != 0)
        return (false);
    if (nbr2 > MAX_FLOAT || nbr2 < MIN_FLOAT) {
        FLOATOVERLOW = 1;
        return (false);
    }
    // floatform = nbr;
    floatform = static_cast<float>(nbr2);
    if (floatform > MAXCHAR || floatform < MINCHAR)
        CHAROVERLOW = 1;
    if (floatform > MAXINT || floatform < MININT)
        INTOVERLOW = 1;
    return (true);
}

bool    ScalarConverter::checkDouble(std::string const & input) {
    char *endptr;

    size_t dotIdx = input.find('.');
    if (dotIdx == std::string::npos)
        return (false);
    double nbr = std::strtod(input.c_str(), &endptr);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    doubleform = nbr;
    if (doubleform > MAXCHAR || doubleform < MINCHAR)
        CHAROVERLOW = 1;
    if (doubleform > MAXINT || doubleform < MININT)
        INTOVERLOW = 1;
    if (doubleform > MAX_FLOAT || doubleform < MIN_FLOAT)
        FLOATOVERLOW = 1;
    return (true);
}

bool    ScalarConverter::checkChar(std::string const & input) {
    
    if (input.length() == 1) {
        charform = input[0];
        if (!std::isprint(input[0]))
            CHAROVERLOW = 1;
        return (true);
    }
    return (false);
}

int    ScalarConverter::checkinf(std::string const & input) {
    std::string pfloat[] = {"inf", "+inf", "inff", "+inff", "-inf", "-inff", "nan", "nanf"};
    for (size_t i = 0; i < sizeof(pfloat)/sizeof(pfloat[0]); i++) {
        if (input == pfloat[i] && i < 4)
            return (1);
        if (input == pfloat[i] && (i >= 4 && i < 6))
            return (2);
        if (input == pfloat[i] && (i >= 6 && i < sizeof(pfloat)/sizeof(pfloat[0])))
            return (3);
    }
    return (0);
}

bool	ScalarConverter::checkNotaNum(std::string const & input) {
    if (checkinf(input) > 0) {
        INTOVERLOW = 1;
		CHAROVERLOW = 1;
    }
	if (checkinf(input) == 1) {
		floatform = std::numeric_limits<float>::infinity();
		doubleform = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (checkinf(input) == 2) {
		floatform = (-1) * std::numeric_limits<float>::infinity();
		doubleform = (-1) * std::numeric_limits<double>::infinity();
		return (true);
	}
	if (checkinf(input) == 3) {
		floatform = std::numeric_limits<float>::quiet_NaN();
		doubleform = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	return (false);
}

void    ScalarConverter::identifyType(std::string const & input) {
    if (checkInt(input))
        type = INT;
    else if (checkFloat(input))
        type = FLOAT;
    else if (checkDouble(input))
        type = DOUBLE;
    else if (checkChar(input))
        type = CHAR;
    else if (checkNotaNum(input))
        type = NOTNUM;
    return ;
}

void    ScalarConverter::castFromInt() {
	floatform = static_cast<float>(intform);
	doubleform = static_cast<double>(intform);
	charform = static_cast<char>(intform);
	if (!std::isprint(charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::castFromFloat() {
	intform = static_cast<int>(floatform);
	doubleform = static_cast<double>(floatform);
	charform = static_cast<char>(floatform);
	if (!std::isprint(charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::castFromDouble() {
	floatform = static_cast<float>(doubleform);
	intform = static_cast<int>(doubleform);
	charform = static_cast<char>(doubleform);
	if (!std::isprint(charform))
		CHAR_NONPRINT = 1;
}

void    ScalarConverter::castFromChar() {
	floatform = static_cast<float>(charform);
	doubleform = static_cast<double>(charform);
	intform = static_cast<int>(charform);
}

void    ScalarConverter::converter(std::string const & input) {
    identifyType(input);
    switch (type)
	{
		case INT:
			castFromInt();
			break;
		case FLOAT:
			castFromFloat();
			break;
		case DOUBLE:
			castFromDouble();
			break;
		case CHAR:
			castFromChar();
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
		std::cout << charform;
}

void    ScalarConverter::printInt() {
	if (INTOVERLOW)
        std::cout << "impossible";
	else
		std::cout << intform;
}

void    ScalarConverter::printFloat() {
    if (FLOATOVERLOW)
        std::cout << "impossible";
    else if (floatform == static_cast<int>(floatform))
        std::cout << std::fixed << std::setprecision(1) << floatform << "f";
    else
        std::cout << floatform << "f";
}

void    ScalarConverter::printDouble() {
    // std::cout << std::fixed << std::setprecision(1) << doubleform;
    std::cout << doubleform;
}
