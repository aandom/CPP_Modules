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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

int	main(void)
{
	Bureaucrat	br1("br_1", 142);
	Bureaucrat	br2("br_2", 65);
	Bureaucrat	br3("br_3", 6);



	std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << br1 << "\n"
			"\t" << br2 << "\n"
			"\t" << br3 << std::endl << std::endl;
	
	ShrubberyCreationForm	shrubForm("Forest");
	RobotomyRequestForm		robotomyForm("CEO");
	PresidentialPardonForm	pardonForm(br3.getName());

	std::cout << std::endl << "Three forms created:\n"
			"\t" << shrubForm << "\n"
			"\t" << robotomyForm << "\n"
			"\t" << pardonForm << std::endl;

	std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
	br1.signForm(shrubForm);
	// br1.executeForm(shrubForm);
	// br2.executeForm(shrubForm);

	std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
	br3.executeForm(pardonForm);
	br3.signForm(pardonForm);
	br3.executeForm(pardonForm);
	br3.incrementGrade();
	br3.executeForm(pardonForm);

	std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
	br2.executeForm(robotomyForm);
	br2.signForm(robotomyForm);
	br2.executeForm(robotomyForm);
	br3.executeForm(robotomyForm);
	br3.executeForm(robotomyForm);

	std::cout << std::endl;
	return (0);
}