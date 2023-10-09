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
		std::cout << "Usage: ./convert_scalar <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			<< std::endl;
		return (1);
	}
	
	try
	{
		std::cout << YELLOW "---- Converting [" << av[1] << "]" RESET << std::endl;
		ScalarConverter	convert(av[1]);
		std::cout << convert << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED "Input could not be converted: " << e.what() << RESET << std::endl;
	}
	return (0);
}