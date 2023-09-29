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

class Bureaucrat
{
    public:
        Bureaucrat( const std::string & name, int grade);
        Bureaucrat( const Bureaucrat & src);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const & src);

        std::string  getName() const;
        int               getGrade() const;


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