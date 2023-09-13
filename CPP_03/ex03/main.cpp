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
#include "DiamondTrap.hpp"

int	main(void) {
	std::string diamondTrapName = "DT-XXY";
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	DiamondTrap	diamondTrap(diamondTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	diamondTrap.whoAmI();
	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(clapTrap.getDamageP());
	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(scavTrap.getDamageP());
	diamondTrap.attack(scavTrapName);
	scavTrap.takeDamage(diamondTrap.getDamageP());
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.takeDamage(5000);
	diamondTrap.beRepaired(5000);
	diamondTrap.whoAmI();
	return (0);
}