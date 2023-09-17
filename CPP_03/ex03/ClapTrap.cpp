/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:48:07 by aandom            #+#    #+#             */
/*   Updated: 2023/09/11 08:48:07 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    this->_name = "default";
    this->_hit = ClapTrap::defaultHitP;
    this->_energy = ClapTrap::defaultEnergyP;
    this->_damage = ClapTrap::defaultAttackDamage;
    this->_maxhit = ClapTrap::defaultHitP;
    this->_maxenergy = ClapTrap::defaultEnergyP;
    this->_maxdamage = ClapTrap::defaultAttackDamage;
    std::cerr << "ClapTrap default constructor called." << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    this->_hit = ClapTrap::defaultHitP;
    this->_energy = ClapTrap::defaultEnergyP;
    this->_damage = ClapTrap::defaultAttackDamage;
    this->_maxhit = ClapTrap::defaultHitP;
    this->_maxenergy = ClapTrap::defaultEnergyP;
    this->_maxdamage = ClapTrap::defaultAttackDamage;
    std::cerr << "Parameterized ClapTrap constructor with name ["<< name << "]  called." << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    *this = src;
    std::cerr << "ClapTrap copy constructor called." << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void) {
    std::cerr << "ClapTrap with name ["<< this->_name << "]  was destroyed." << std::endl;
    return ;
}

ClapTrap    & ClapTrap::operator=(ClapTrap const & src){
    if (this != &src) {
        this->_name = src.getName();
        this->_hit = src.getHitP();
        this->_energy = src.getEnergyP();
        this->_damage = src.getDamageP();
    }

    return (*this);
}

std::string ClapTrap::getName(void) const {
    return (this->_name);
}

unsigned int    ClapTrap::getHitP(void) const {
    return (this->_hit);
}

unsigned int    ClapTrap::getEnergyP(void) const {
    return (this->_energy);
}

unsigned int    ClapTrap::getDamageP(void) const {
    return (this->_damage);
}

void    ClapTrap::attack(const std::string& target) {
    std::string tarname;

    if (this->_hit == 0) {
        std::cout << "ClapTrap [" << this->_name << "] can not attack: it has no Hit point" << std::endl;
        return ;
    }
    if (this->_energy == 0) {
        std::cout << "ClapTrap [" << this->_name << "] can not attack: it has no energy to attack" << std::endl;
        return ;
    }
    if (target == this->_name) {
        tarname = "itself";
    }
    else
        tarname = target;
    this->_energy--;
    std::cout << "ClapTrap [" << this->_name << "] attacks " << tarname
        << " that results " << this->_damage << " damage" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit == 0) {
        std::cout << "[" << this->_name << "] can not take anymore damage: it has no hit point so it can't repair"<< std::endl;
        return ;
    }
    if (this->_energy == 0) {
        std::cout << "[" << this->_name << "] can not take anymore damage: it has no energy so it can't repair" << std::endl;
        return ;
    }
    if ((int)this->_hit - (int) amount <= 0) {
        this->_hit = 0;
        std::cout << "[" << this->_name << "] take " << amount << " damage and it is destroyed" << std::endl;
        return ; 
    }
    else {
        this->_hit -= amount;
        std::cout << "[" << this->_name << "] take " << amount << " damage " << std::endl;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount) {
     if (this->_hit == 0) {
        std::cout << "[" << this->_name << "] can not repair anymore: it has no hit point"<< std::endl;
        return ;
    }
     if (this->_energy == 0) {
        std::cout << "[ " << this->_name << " ] can not repair anymore: it has no energy"<< std::endl;
        return ;
    }
    if (this->_hit + amount > this->_maxhit) {
        amount = this->_maxhit - this->_hit;
    }
    if (amount == 0) {
        this->_energy--;
        std::cout << "[" << this->_name << "] tries to repair while the amount to repair is 0 or it doesn't need any repair" << std::endl;
        return ;
    }
    this->_energy--;
    this->_hit += amount;
    std::cout << "[" << this->_name << "] repairs " << amount << " hit point " << std::endl;
    return ;
}



