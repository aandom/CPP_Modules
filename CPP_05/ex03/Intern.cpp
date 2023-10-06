/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:52:41 by aandom            #+#    #+#             */
/*   Updated: 2023/10/06 11:47:24 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern & src){
    (void) src;
}

Intern::~Intern(){
}

Intern & Intern::operator=(const Intern & src) {
    (void) src;
    return (*this);
}


AForm *    createPardonForm( std::string const target) {
    return (new PresidentialPardonForm(target));
}
AForm *   createRequestForm( std::string const target) {
    return (new RobotomyRequestForm(target));
}
AForm *   createShrubberyForm( std::string const target) {
    return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ( YELLOW "Error: Invalid Form Name." RESET);	
}


AForm    * Intern::makeForm(std::string name, std::string target) {

    t_forms myforms[3] = {
        {"robotomy request", createRequestForm},
        {"presidential pardon" , createPardonForm},
        {"shrubbery creation", createShrubberyForm}
    };
    for (size_t i = 0; i < 3; i++) {
        if (myforms[i].name == name) {
            std::cout << "Intern creates " << name << " Form."<< std::endl;
            return (myforms[i].ffunction(target));
        }        
    }
    std::cout << "Intern cannot create " << name << " Form" << std::endl;
    throw Intern::InvalidFormName();
    
    // std::string fNames[3] = {
    //     "robotomy request",
    //     "presidential pardon",
    //     "shrubbery creation"
    // };
    // Form * forms [] = {
    //     createRequestForm(target),
    //     createPardonForm(target),
    //     createShrubberyForm(target)
    // };

    // for (size_t i = 0; i < 3; i++) {
    //     if (fNames[i] == name) {
    //         std::cout << "Intern creates " << name << " Form."<< std::endl;
    //         return (forms[i]);
    //     }        
    // }
    // std::cout << "Intern cannot create " << name << " Form" << std::endl;
    // throw Intern::InvalidFormName();

}
    