/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:03:25 by aandom            #+#    #+#             */
/*   Updated: 2023/09/23 06:03:25 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

#define RESET "\e[0m"
#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat( std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const & src);

        std::string  getName() const;
        int               getGrade() const;

        void        signForm(Form  & form);
        void        executeForm(Form const & form);


        void    incrementGrade();
        void    decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char * what () const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char * what () const throw();

        };

    private:
        Bureaucrat();
        std::string const _name;
        int               _grade;

};

std::ostream &	operator<<(std::ostream & out, Bureaucrat const & src);



# endif