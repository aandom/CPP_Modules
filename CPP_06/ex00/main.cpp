/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:17:14 by aandom            #+#    #+#             */
/*   Updated: 2023/10/09 16:17:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

int	main(int ac, char ** av)
{
	if (ac != 2)
	{
		std::cerr << RED << "ERROR: Invalid number of Argument \n"
				  << "Usage: ./converter <input>\n"
					 "Valid Input: [int/float/double/char]." << RESET
			<< std::endl;
		return (1);
	}
	
	try
	{
		std::cout << YELLOW "---- Trying to Convert [" << av[1] << "]" RESET << std::endl;
		// ScalarConverter	convert(av[1]);
		ScalarConverter::converter(av[1]);
		std::cout<<std::endl;
		// ScalarConverter::converter("234564");
		// std::cout << convert << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED "Input could not be converted : \n" RESET << e.what() << std::endl;
	}
	return (0);
}