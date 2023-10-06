/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:20:48 by aandom            #+#    #+#             */
/*   Updated: 2023/10/06 11:50:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("PresidentialPardonForm", 25, 5),
                                                                             _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src),
                                                                             _target(src._target) {    
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & src) {
    this->_target = src._target;
    return(*this);
}

// void    PresidentialPardonForm::execute(Bureaucrat const & executor) const{
//     if (!this->getSigned()) {
//         throw Form::FormNotSignedException();
//     }
//     if (executor.getGrade() > this->getGToExec()) {
//         throw Form::GradeTooLowException();
//     }
//     else
//         std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
// }


void    PresidentialPardonForm::undertakeExecution() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}