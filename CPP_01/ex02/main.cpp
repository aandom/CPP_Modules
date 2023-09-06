/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:11:06 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 12:11:06 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "[---- Memory addresses ----]\n"
				<< "The memory address of the string variable:\t" << &str << "\n"
				<< "The memory address held by stringPTR:\t\t" << stringPTR << "\n"
				<< "The memory address held by stringREF:\t\t" << &stringREF << std::endl;

	std::cout << "\n[---- Vlues ----]\n"
				<< "The value of the string variable:\t[" << str << "]\n"
				<< "The value pointed to by stringPTR:\t[" << *stringPTR << "]\n"
				<< "The value pointed to by stringREF:\t[" << stringREF << "]" << std::endl;
	return (0);
}