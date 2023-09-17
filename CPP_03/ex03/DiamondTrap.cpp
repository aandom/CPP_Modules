/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:35:22 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 20:35:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap() {
    this->_hit = FragTrap::_maxhit;
    this->_energy = ScavTrap::_maxenergy;
    this->_damage = FragTrap::_maxdamage;
    this->_maxhit = FragTrap::_maxhit;
    this->_maxenergy = ScavTrap::_maxenergy;
    this->_maxdamage = FragTrap::_maxdamage;
    std::cerr << "DiamondTrap default constructor called." << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
                                             FragTrap(name + "_frag_name"), 
                                             ScavTrap(name + "_scav_name"), _name(name) {
    this->_hit = FragTrap::_maxhit;
    this->_energy = ScavTrap::_maxenergy;
    this->_damage = FragTrap::_maxdamage;
    this->_maxhit = FragTrap::_maxhit;
    this->_maxenergy = ScavTrap::_maxenergy;
    this->_maxdamage = FragTrap::_maxdamage;
    std::cerr << "Parameterized DiamondTrap constructor with name ["<< name << "]  called." << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(), FragTrap(), ScavTrap() {
    *this = src;
    std::cerr << "DiamondTrap copy constructor called." << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void) {
    std::cerr << "DiamondTrap with name ["<< this->_name << "]  was destroyed." << std::endl;
    return ;
}

DiamondTrap    & DiamondTrap::operator=(DiamondTrap const & src){
    if (this != &src) {
        this->_name = src.getName();
        this->_hit = src.getHitP();
        this->_energy = src.getEnergyP();
        this->_damage = src.getDamageP();
    }
    return (*this);
}

void    DiamondTrap::whoAmI(void) {
	if (this->_hit == 0)
		std::cout << "DiamondTrap [" << this->_name
			<< "] with a ClapTrap name [" << ClapTrap::_name
			<< "] has no hit point, so can't introduce itself."<< std::endl;
	else
		std::cout << "Hi I am DiamondTrap [ " << this->_name
			<< "] and I have a ClapTrap name [ " << ClapTrap::_name
			<< "] ."<< std::endl;
	return ;
}