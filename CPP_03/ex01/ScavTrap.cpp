/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:16:08 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 02:16:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->_hit = SCAVTRAP_DHP;
    this->_energy = SCAVTRAP_DEP;
    this->_damage = SCAVTRAP_DAD;
    this->_maxhit = SCAVTRAP_DHP;
    this->_maxenergy = SCAVTRAP_DEP;
    this->_maxdamage = SCAVTRAP_DAD;
    std::cerr << "ScavTrap default constructor called." << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string & name) : ClapTrap(name) {
    this->_hit = SCAVTRAP_DHP;
    this->_energy = SCAVTRAP_DEP;
    this->_damage = SCAVTRAP_DAD;
    this->_maxhit = SCAVTRAP_DHP;
    this->_maxenergy = SCAVTRAP_DEP;
    this->_maxdamage = SCAVTRAP_DAD;
    std::cerr << "Parameterized ScavTrap constructor with name ["<< name << "]  called." << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap() {
    *this = src;
    std::cerr << "ScavTrap copy constructor called." << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void) {
    std::cerr << "ScavTrap with name ["<< this->_name << "]  was destroyed." << std::endl;
    return ;
}

ScavTrap    & ScavTrap::operator=(ScavTrap const & src){
    if (this != &src) {
        this->_name = src.getName();
        this->_hit = src.getHitP();
        this->_energy = src.getEnergyP();
        this->_damage = src.getDamageP();
    }
    return (*this);
}

void    ScavTrap::attack(std::string & target) {
    std::string tarname;

    if (this->_hit == 0) {
        std::cout << "ScavTrap [" << this->_name << "] can not attack: it has no Hit point" << std::endl;
        return ;
    }
    if (this->_energy == 0) {
        std::cout << "ScavTrap [" << this->_name << "] can not attack: it has no energy to attack" << std::endl;
        return ;
    }
    if (target == this->_name) {
        tarname = "itself";
    }
    else
        tarname = target;
    this->_energy--;
    std::cout << "ScavTrap [" << this->_name << "] attacks " << tarname
        << " that results " << this->_damage << " damage" << std::endl;

}


void    ScavTrap::guardGate(void) {
	if (this->_hit == 0)
		std::cout << "ScavTrap ["<< this->_name
			<< "] can not be in Gate keeper mode: it has no hit point" << std::endl;
	else
		std::cout << "ScavTrap [" << this->_name
			<< "] is in Gate keeper mode" << std::endl;
	return ;
}