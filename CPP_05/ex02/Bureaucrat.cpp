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


Bureaucrat:: Bureaucrat( std::string const & name, int grade) : _name (name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
   this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src) : _name(src._name), _grade(src._grade) {
    //    this->_grade = src.getGrade();
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(  Bureaucrat const & src ) {
    if ( this != &src ) {
       this->_grade = src.getGrade();
    }
    return *this;
}


std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void    Bureaucrat::incrementGrade() {
    std::cout << "Incrementing grade ..."<< std::endl;
    if (this->_grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrementGrade() {
    std::cout << "Decrementing grade ..."<< std::endl;
    if ( this->_grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void    Bureaucrat::signForm(AForm  & form) {
    try
    {
       form.beSigned(*this);
       std::cout << this->_name <<  " signed " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << YELLOW << this->_name <<  " couldn’t sign " << form.getName()
                  << " because his/her grade, " << this->getGrade()
                  << " is less than the minimum grade, "  << form.getGToSign() 
                  << " required to sign "<< form.getName() << RESET <<  std::endl;
        // std::cerr << e.what() << '\n';
    }
    catch(AForm::FormIsAlreadySignedException &e)
    {
        std::cerr << YELLOW << this->_name <<  " couldn’t sign " << form.getName()
                  << " because " << e.what() << RESET <<  std::endl;
        // std::cerr << e.what() << '\n';
    }
}

void    Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << this->_name <<  " executed " << form.getName() << std::endl;
    }
    catch (AForm::FormNotSignedException &e) {
        std::cerr << YELLOW << this->_name <<  " couldn’t execute " << form.getName()
                  << " because the form "<< form.getName()
                  << " is not signed yet! " RESET <<  std::endl;
        // std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeTooLowException &e) {
        std::cerr << YELLOW << this->_name <<  " couldn’t execute " << form.getName()
                  << " because his/her grade, " << this->getGrade()
                  << " is less than the minimum grade, "  << form.getGToExec() 
                  << " required to sign "<< form.getName() << RESET <<  std::endl;
        // std::cerr << e.what() << '\n';
    }      
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ( YELLOW "Error: grade too High. grade is greater than the highest possible level" RESET);	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ( YELLOW "Error: grade too Low. grade is lower than the lowest possible level" RESET);	
}

std::ostream& operator<<( std::ostream& out, const Bureaucrat& src ) {
    out << "Bureaucrat Name : " << src.getName() << ", Bureaucrat Grade : " << src.getGrade();
    return out;
}


