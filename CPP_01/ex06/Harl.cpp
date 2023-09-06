/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:54:47 by aandom            #+#    #+#             */
/*   Updated: 2023/08/30 01:54:47 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl() {
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!"
		<< std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, "
		"I wouldn't be asking for more!"
		<< std::endl;
	return ;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. "
		"I've been coming for years whereas you started working here "
		"since last month."
		<< std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
	return ;
}

void    Harl::complain( std:: string level ) {
    m_func  members[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
	int	index;
    while (i < 4 && levels[i].compare(level)) {
        i++ ;
	}
	index = i;
    switch (index)
	{
		case 0:
			(this->*members[index])();
			index++;
		case 1:
			(this->*members[index])();
			index++;
		case 2:
			(this->*members[index])();
			index++;
		case 3:
			(this->*members[index])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

