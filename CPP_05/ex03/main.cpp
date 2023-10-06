/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:12:39 by aandom            #+#    #+#             */
/*   Updated: 2023/09/29 11:12:39 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

void	createForm(std::string formName, std::string target)
{
	std::cout << std::endl << "\t---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	inter = Intern();
	Bureaucrat Br_1("Boss", 1);
	AForm *	form;
	try
	{
		form = inter.makeForm(formName, target);
		std::cout << *form << std::endl;
		Br_1.signForm(*form);
		Br_1.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::string const	shrubbery = "shrubbery creation";
	std::string const	robotomy = "robotomy request";
	std::string const	presidential = "presidential pardon";

	createForm(shrubbery, "target_1");
	createForm(robotomy, "target_2");
	createForm(presidential, "target_3");
	createForm("Invalid", "target_4");
	createForm("", "");	
	return (0);
}
