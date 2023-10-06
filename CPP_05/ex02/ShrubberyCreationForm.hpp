/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:57:59 by aandom            #+#    #+#             */
/*   Updated: 2023/10/06 12:00:35 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ShrubberyCreationForm( const std::string  & target);
        ~ShrubberyCreationForm();
        

        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & src);
        // void        execute(Bureaucrat const & executor) const;
        void        undertakeExecution() const;
        
        
    private:
        std::string _target;
		static std::string const	_asciiTree;
        static std::string const    _asciiTree_2;
        static std::string const    _asciiTree_3;
        static std::string const    _asciiTree_4;
        static std::string const    _asciiTree_5;
        
        ShrubberyCreationForm();
};

# endif