/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:58:08 by aandom            #+#    #+#             */
/*   Updated: 2023/09/30 08:58:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

Form::Form( const std::string& name, int gToSign, int gToExec) : _fname (name), _signed(false), _execgrade(gToExec) ,_signgrade(gToSign) {
	if (gToSign < 1 || gToExec < 1 )
		throw (Form::GradeTooHighException());
	if (gToSign > 150 || gToExec > 150)
		throw (Form::GradeTooLowException());
	return ;
}

Form::Form( const Form & src) : _fname(src._fname), 
                                _signed(false),
                                _execgrade(src._execgrade),
                                _signgrade(src._signgrade) {
}

Form::~Form() {}

Form    & Form::operator=( const Form & src) {
    if (this != &src) {
        this->_signed = src.getSigned();
    }
    return (*this);
}

std::string Form::getName() const {
    return this->_fname;
}

bool   Form::getSigned() const {
    return this->_signed;
}

int   Form::getGToSign() const {
    return this->_signgrade;
}

int   Form::getGToExec() const {
    return this->_execgrade;
}

void    Form::beSigned(const Bureaucrat& src) {
    if ( src.getGrade() > this->_signgrade )
        throw Form::GradeTooLowException();
    this->_signed = true;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ( YELLOW "Error: Form grade too High." RESET);	
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ( YELLOW "Error: Form grade too Low." RESET);	
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ( YELLOW "Error: Form not is signed yet." RESET);	
}

std::ostream& operator<<( std::ostream& out, const Form& src ) {
    out << "Form Name : " << src.getName()
        << ", Signature : [" << (src.getSigned() ? "signed" : "unsigned") 
        << "], Grade required to sign : " << src.getGToSign()
        << ", Grade required to exec : " << src.getGToExec()
        << std::endl;
    return out;
}
