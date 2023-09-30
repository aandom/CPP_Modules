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
#include "Form.hpp"

#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"


void	trycreateobject(std::string name, int gradeToSign, int gradeToExecute)
{
	std::cout << std::endl << "-- Creating form named [\""
		<< name << "\"] with grade to sign " << gradeToSign
		<< " and grade to execute " << gradeToExecute << ":" << std::endl;
	try
	{
		Form	form(name, gradeToSign, gradeToExecute);
		std::cout << form << " successfully created." << std::endl;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
		std::cout << " failed to create form." << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << "\t---- TEST FORM ATTRIBUTE CONSTRUCTOR ----" << std::endl;
	trycreateobject("Simple Form", 42, 42);
	trycreateobject("Signable/Executable Form", 150, 1);
	trycreateobject("Unsignable Form", 151, 1);
	trycreateobject("Unexecutable Form", 1, 0);
	trycreateobject("Unexecutable Form", -10, 140);

	{
		std::cout << std::endl << "\t---- TEST FORM COPY CONSTRUCTOR ----" << std::endl;
		Form form("FormXYZ", 42, 42);
		std::cout << "Original Form \n \t" << form << std::endl;
		Form copiedform(form);
		std::cout << "copied Form \n \t" << copiedform << std::endl;
	}
	{
		std::cout << std::endl << "\t---- TEST FORM ASSIGNMENT OPERATOR ----" << std::endl;
		Bureaucrat	bureaucrat("Richard", 42);
		Form form1("Form #1", 150, 1);
		Form form2("Form #2", 42, 42);

		std::cout << "Two forms created:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		bureaucrat.signForm(form2);
		std::cout << "after sign:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		form1 = form2;
		std::cout << form1.getName() << " = " << form2.getName() << "\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
	}
	{
		std::cout << std::endl << "\t---- TEST FOR SIGNING ----" << std::endl;
		Bureaucrat	b1("Nicholas", 150);
		Bureaucrat	b2("Sam", 42);
		Bureaucrat	b3("Bob", 1);

		Form	basicForm("Basic Form", 150, 150);
		Form	averageForm("Visa Form", 42, 42);
		Form	topForm("Residence Form", 1, 1);

		std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << b1 << "\n"
			"\t" << b2 << "\n"
			"\t" << b3 << std::endl;

		std::cout << std::endl << "Attempting to sign " << std::endl;
		std::cout << "\t" << basicForm << std::endl;
		b1.signForm(basicForm);
		b2.signForm(basicForm);
		b3.signForm(basicForm);
		std::cout << std::endl;

		std::cout << std::endl << "Attempting to sign " << std::endl;
		std::cout << "\t" << averageForm << std::endl;
		b1.signForm(averageForm);
		b2.signForm(averageForm);
		b3.signForm(averageForm);
		std::cout << std::endl;
	
		std::cout << std::endl << "Attempting to sign " << std::endl;
		std::cout << "\t" << topForm << std::endl;
		b1.signForm(topForm);
		b2.signForm(topForm);
		b3.signForm(topForm);
		std::cout << std::endl;
	}
	return (0);
}
