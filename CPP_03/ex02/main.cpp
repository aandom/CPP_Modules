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
#include "FragTrap.hpp"

int	main(void) {
	std::string	fragTrapName = "FT-356";
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	FragTrap	fragTrap(fragTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	fragTrap.highFivesGuys();
	clapTrap.attack(scavTrapName);
	scavTrap.attack(clapTrapName);
	fragTrap.attack(scavTrapName);
	scavTrap.takeDamage(ClapTrap::defaultAttackDamage);
	scavTrap.attack(fragTrapName);
	// fragTrap.takeDamage(SCAVTRAP_DAD);
	// fragTrap.beRepaired(5);
	scavTrap.guardGate();
	// for (int i = 0; i <= 100; i++) {
	// 	fragTrap.attack(scavTrapName);
	// 	scavTrap.takeDamage(FRAGTRAP_DAD);
	// }
	scavTrap.beRepaired(20);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(5000);
	fragTrap.highFivesGuys();
	return (0);
}