/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:07:17 by aandom            #+#    #+#             */
/*   Updated: 2023/09/30 20:21:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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


class AForm
{
    public:
        AForm(const std::string& name, int gToSign, int gToExec);
        AForm(const AForm& src);
        virtual ~AForm();

        AForm&   operator=(const AForm& src);

        std::string getName() const;
        bool        getSigned() const;
        int         getGToSign() const;
        int         getGToExec() const;

        void        beSigned(const Bureaucrat & src);
        void        execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
         };
        
    private:
        AForm();
        std::string const _fname;
        bool              _signed;
        int         const _execgrade;
        int         const _signgrade;
};

std::ostream &	operator<<(std::ostream & out, AForm const & src);

# endif