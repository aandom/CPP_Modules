/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:26:47 by aandom            #+#    #+#             */
/*   Updated: 2023/10/03 14:45:09 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : Form("RobotomyRequestForm", 72, 45),
                                                                             _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : Form(src),
                                                                             _target(src._target) {    
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & src) {
    this->_target = src._target;
    return(*this);
}

// void    RobotomyRequestForm::execute(Bureaucrat const & executor) const{
//     if (!this->getSigned()) {
//         throw Form::FormNotSignedException();
//     }
//     if (executor.getGrade() > this->getGToExec()) {
//         throw Form::GradeTooLowException();
//     }
//     else {
//         std::cout << "making some drilling noise" << std::endl;
//         if ( std::rand() % 2  == 1)
//             std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
//         else
//             std::cout << "robotomizing " << this->_target << " failed" << std::endl;
//     }
// }

void    RobotomyRequestForm::undertakeExecution() const {
        std::cout << "making some drilling noise" << std::endl;
        if ( std::rand() % 2  == 1)
            std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
        else
            std::cout << "robotomizing " << this->_target << " failed" << std::endl;
}