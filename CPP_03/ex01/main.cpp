/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:48:14 by aandom            #+#    #+#             */
/*   Updated: 2023/09/11 08:48:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(ClapTrap::defaultAttackDamage);
	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(SCAVTRAP_DAD);
	clapTrap.beRepaired(5000);
	scavTrap.guardGate();
	for (int i = 0; i < 50; i++)
		scavTrap.beRepaired(5000);
	scavTrap.attack(scavTrapName);
	scavTrap.guardGate();
	scavTrap.takeDamage(5000);
	return (0);
}