/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:35:22 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 20:35:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    this->_hit = FRAGTRAP_DHP;
    this->_energy = FRAGTRAP_DEP;
    this->_damage = FRAGTRAP_DAD;
    this->_maxhit = FRAGTRAP_DHP;
    this->_maxenergy = FRAGTRAP_DEP;
    this->_maxdamage = FRAGTRAP_DAD;
    std::cerr << "FragTrap default constructor called." << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hit = FRAGTRAP_DHP;
    this->_energy = FRAGTRAP_DEP;
    this->_damage = FRAGTRAP_DAD;
    this->_maxhit = FRAGTRAP_DHP;
    this->_maxenergy = FRAGTRAP_DEP;
    this->_maxdamage = FRAGTRAP_DAD;
    std::cerr << "Parameterized FragTrap constructor with name ["<< name << "]  called." << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap() {
    *this = src;
    std::cerr << "FragTrap copy constructor called." << std::endl;
    return ;
}

FragTrap::~FragTrap(void) {
    std::cerr << "FragTrap with name ["<< this->_name << "]  was destroyed." << std::endl;
    return ;
}

FragTrap    & FragTrap::operator=(FragTrap const & src){
    if (this != &src) {
        this->_name = src.getName();
        this->_hit = src.getHitP();
        this->_energy = src.getEnergyP();
        this->_damage = src.getDamageP();
    }
    return (*this);
}

void    FragTrap::highFivesGuys(void) {
	if (this->_hit == 0)
		std::cout << "FragTrap [" << this->_name
			<< " ] can not high five: it has no hit point."<< std::endl;
	else
		std::cout << "FragTrap [" << this->_name << " ] is waving for high five" << std::endl;
	return ;
}