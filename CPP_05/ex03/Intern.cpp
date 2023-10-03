/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:52:41 by aandom            #+#    #+#             */
/*   Updated: 2023/10/03 19:36:18 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern & src){
}

Intern & Intern::operator=(const Intern & src) {
    return (*this);
}

Form *    createPardonForm(std::string target) {
    return (new PresidentialPardonForm(target));
}
Form *   createRequestForm(std::string target) {
    return (new RobotomyRequestForm(target));
}
Form *   createShrubberyForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}


Form    & Intern::makeForm(std::string name, std::string target) {
    t_forms forms[3] = {
        {"Pardon Form", createPardonForm},
        {"Request Form", createRequestForm},
        {"Creation Form", createShrubberyForm}
    };
    
}