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

// int main( void )
// {
//     try {
//         Bureaucrat bureaucrat("Amran", 0);

//         std::cout << bureaucrat << std::endl;

//         bureaucrat.incrementGrade();
//         std::cout << bureaucrat << std::endl;
//         bureaucrat.decrementGrade();
//         std::cout << bureaucrat << std::endl;
//         bureaucrat.decrementGrade();
//         std::cout << bureaucrat << std::endl;
//         bureaucrat.decrementGrade();
//         std::cout << bureaucrat << std::endl;
//     } catch (Bureaucrat::GradeTooHighException &e) {
//         std::cout << e.what() << std::endl;
//     } catch (Bureaucrat::GradeTooLowException &e) {
//         std::cout << e.what() << std::endl;
//     }

//     return 1;
// }



#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"


void	trycreateobject(std::string name, int grade)
{
	std::cout << std::endl << "-- Creating Bureaucrat named [\""
		<< name << "\"] with grade to sign " << grade << ":" << std::endl;
	try
	{
		Bureaucrat	br(name, grade);
		std::cout << "Bureaucrat "<< name << " successfully created." << std::endl;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
		std::cout << " failed to create Bureaucrat " << name << "." << std::endl;
	}
}

void    tryincrement(Bureaucrat & src) {
    
    std::cout << std::endl << "-- Before Increment : " << std::endl;
    std::cout << src << std::endl;
	try
	{
		src.incrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
    std::cout << std::endl << "-- After Increment : " << std::endl;
    std::cout << src << std::endl;
}

void    trydecrement(Bureaucrat & src) {
    
    std::cout << std::endl << "-- Before Decrement : " << std::endl;
    std::cout << src << std::endl;
	try
	{
		src.decrementGrade();
	}
	catch(std::exception const & e) {
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
    std::cout << std::endl << "-- After Decrement : " << std::endl;
    std::cout << src << std::endl;
}

int	main(void)
{
	std::cout << std::endl << "\t---- TEST Bureaucrat CONSTRUCTOR ----" << std::endl;
	trycreateobject("John", 42);
	trycreateobject("Sam", 150);
	trycreateobject("Peter", 151);
	trycreateobject("Linda", 1);
	trycreateobject("kelly", -10);
	trycreateobject(" ",  0);

	{

		std::cout << std::endl << "\n\t---- TEST INCREMENT  ----" << std::endl;
        Bureaucrat	br1("John", 42);
        Bureaucrat	br2("Sam", 150);
        Bureaucrat	br4("Linda", 1);
        tryincrement(br1);
        tryincrement(br1);
        tryincrement(br2);
        tryincrement(br2);
        tryincrement(br4);
        tryincrement(br4);
	}
	{
		std::cout << std::endl << "\n\t---- TEST DECREMENT  ----" << std::endl;
        Bureaucrat	br1("John", 42);
        Bureaucrat	br2("Sam", 150);
        Bureaucrat	br4("Linda", 1);
        trydecrement(br1);
        trydecrement(br1);
        trydecrement(br2);
        trydecrement(br2);
        trydecrement(br4);
        trydecrement(br4);
	}
	return (0);
}
