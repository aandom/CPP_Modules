/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:26:55 by aandom            #+#    #+#             */
/*   Updated: 2023/10/06 11:51:50 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define  ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm( const std::string  & target);
        ~RobotomyRequestForm();
        

        RobotomyRequestForm & operator=(const RobotomyRequestForm & src);
        // void        execute(Bureaucrat const & executor) const;
        void        undertakeExecution() const;
        
        
    private:
        std::string _target;
        
        RobotomyRequestForm();
};



# endif