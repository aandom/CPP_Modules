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

AForm::AForm( const std::string& name, int gToSign, int gToExec) : _fname (name), _signed(false), _execgrade(gToExec) ,_signgrade(gToSign) {
	if (gToSign < 1 || gToExec < 1 )
		throw (AForm::GradeTooHighException());
	if (gToSign > 150 || gToExec > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::AForm( const AForm & src) : _fname(src._fname), 
                                _signed(false),
                                _execgrade(src._execgrade),
                                _signgrade(src._signgrade) {
}

AForm::~AForm() {}

AForm    & AForm::operator=( const AForm & src) {
    if (this != &src) {
        this->_signed = src.getSigned();
    }
    return (*this);
}

std::string AForm::getName() const {
    return this->_fname;
}

bool   AForm::getSigned() const {
    return this->_signed;
}

int   AForm::getGToSign() const {
    return this->_signgrade;
}

int   AForm::getGToExec() const {
    return this->_execgrade;
}

void    AForm::beSigned(const Bureaucrat& src) {
    if ( src.getGrade() > this->_signgrade )
        throw AForm::GradeTooLowException();
    if (this->getSigned())
        throw AForm::FormIsAlreadySignedException();
    this->_signed = true;
}

void    AForm::execute(Bureaucrat const & executor) const {

    if (!this->getSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGToExec()) {
        throw AForm::GradeTooLowException();
    }
    this->undertakeExecution();
}


const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ( YELLOW "Error: Form grade too High." RESET);	
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ( YELLOW "Error: Form grade too Low." RESET);	
}

const char *	AForm::FormIsAlreadySignedException::what(void) const throw()
{
	return ( YELLOW "Form is already signed by other Bureaucrat." RESET);	
}

const char *	AForm::FormNotSignedException::what(void) const throw()
{
	return ( YELLOW "Error: Form not is signed yet." RESET);	
}

std::ostream& operator<<( std::ostream& out, const AForm& src ) {
    out << "Form Name : " << src.getName()
        << ", Signature : [" << (src.getSigned() ? "signed" : "unsigned") 
        << "], Grade required to sign : " << src.getGToSign()
        << ", Grade required to exec : " << src.getGToExec()
        << std::endl;
    return out;
}
