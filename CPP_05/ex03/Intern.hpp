/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:50:13 by aandom            #+#    #+#             */
/*   Updated: 2023/10/04 07:17:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp";
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern (const Intern & src);
        ~Intern();

        Intern & operator=(const Intern & src);
        
        
        Form & makeForm(std::string name, std::string target);

        class InvalidFormName : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        typedef struct s_forms {
            std::string const & name;
            Form * (*ffunction)(const std::string );
        }   t_forms;
};

# endif