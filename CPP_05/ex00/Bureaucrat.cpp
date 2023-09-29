/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:45:54 by aandom            #+#    #+#             */
/*   Updated: 2023/09/29 10:45:54 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name (name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
//    _name = name;
   _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name), _grade(src._grade) {
    //    _name = src->_name;
    //    _grade = src->_grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src ) {
    if ( this != &src ) {
        _grade = src.getGrade();
        // _name = src.getName();
    }
    return *this;
}


std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
   _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Exception: grade too High.");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Exception: grade too Low.");	
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& src ) {
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return out;
}


