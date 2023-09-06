/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 03:08:59 by aandom            #+#    #+#             */
/*   Updated: 2023/08/30 03:08:59 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


// int main( void ) {

//     // std::string input;
//     // Harl        harl;

//     // do
//     // {
//     //     std::cout << "Enter a level: ";
//     //     std::cin >> input;
//     //     harl.complain(input);
//     // } while (input.compare("exit"));

//     // return 0;

//     Harl	harl;

// 	harl.complain("DEBUG");
// 	harl.complain("ERROR");
// 	harl.complain("INFO");
// 	harl.complain("WARNING");
// 	harl.complain("BAD_JOKES");
// 	return ( 0 );
// }

int	main( int ac, char **av )
{
	Harl	harlFilter;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl
			<< "Levels [ DEBUG - INFO - WARNING - ERROR ]" << std::endl;
		return ( 0 );
	}
	harlFilter.complain(av[1]);
	return ( 0 );
}