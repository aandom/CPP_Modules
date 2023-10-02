/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:55:12 by aandom            #+#    #+#             */
/*   Updated: 2023/10/03 02:02:36 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm(const PresidentialPardonForm & src);
        PresidentialPardonForm( const std::string  & target);
        ~PresidentialPardonForm();
        

        PresidentialPardonForm & operator=(const PresidentialPardonForm & src);
        void        execute(Bureaucrat const & executor) const;
        
        
    private:
        std::string _target;
        
        PresidentialPardonForm();
};

# endif