/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:07:17 by aandom            #+#    #+#             */
/*   Updated: 2023/10/06 11:00:44 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

#define RESET "\e[0m"
#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class Bureaucrat;


class Form
{
    public:
        Form(const std::string& name, int gToSign, int gToExec);
        Form(const Form& src);
        ~Form();

        Form&   operator=(const Form& src);

        std::string getName() const;
        bool        getSigned() const;
        int         getGToSign() const;
        int         getGToExec() const;

        void        beSigned(const Bureaucrat & src);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
         };
        class FormIsAlreadySignedException : public std::exception {
            public:
                virtual const char* what() const throw();
         };
        
    private:
        Form();
        std::string const _fname;
        bool              _signed;
        int         const _execgrade;
        int         const _signgrade;
};

std::ostream &	operator<<(std::ostream & out, Form const & src);

# endif