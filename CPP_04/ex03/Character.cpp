/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:06 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 11:01:06 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void) : _name("default") {
    std::cout << "Character default Constructor called." << std::endl;
    this->_initInv();
    return ;
}

Character::Character(Character const & src) {
    std::cout << "Character copy Constructor called." << std::endl;
    this->_initInv();
    *this = src;
    return ;
}

Character::Character(std::string const & name) : _name(name) {
    std::cout << "Character Parameterized Constructor called." << std::endl;
    this->_initInv();
    return ;
}

Character::~Character() {
    std::cout << "Character Destructor called for " << this->_name << std::endl;
    this->_removeInv();
    return ;
}

Character   & Character::operator=(Character const & src) {

	std::cout << "Character assignment operator overload called." << std::endl;
	this->_name = src._name;
	this->_removeInv();
	for (int i = 0; i < this->_invsize; i++)
	{
		if (src._inv[i] != NULL)
			this->_inv[i] = src._inv[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const {
    return (this->_name);
}
void     Character::setName(std::string const & name) {
   this->_name = name;
}

void    Character::equip(AMateria* m) {

    if(!m) {
        std::cout << this->_name << " : can not equip : no equipment found!" << std::endl;
        return ;
    }
    for (size_t i = 0; i < this->_invsize; i++)
    {
        if (this->_inv[i] == NULL)
        {
            this->_inv[i] = m;
            std::cout << this->_name << " equipped with " << m->getType()
                      << "materia and its index is " << i << std::endl;
            return ;    
        }
    }
    std::cout << this->_name << " can not equip anymore : no space left for another materia" << std::endl;
    return ;
}

void    Character::unequip(int idx) {

    if(idx < 0 || idx >= this->_invsize) {
        std::cout << this->_name << " : can not unequip : Invalid Index!" << std::endl;
        return ;
    }

    if (this->_inv[idx] == NULL) {
     
        std::cout << this->_name << " : can not unequip :No Materia found at given index "
                 << idx << std::endl;
        return ;    
    }
    std::cout << this->_name << " unequipped " << this->_inv[idx]->getType() << " : from index " << idx << std::endl;
    this->_inv[idx] = NULL;
    return ;
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx >= this->_invsize)
	{
		std::cout << this->_name << ": "
			"Can't use item at inventory index " << idx
			<< ". It's not a valid index!" << std::endl; 
		return ;
	}
	if (this->_inv[idx] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inv[idx]->use(target);
	}
	else
		std::cout << this->_name
			<< ": Can not use item in inventory at index "
			<< idx << " : no item at the given index" << std::endl;
	return ;
}

void	Character::dispInv(void) const {
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (size_t i = 0; i < this->_invsize; i++) {
		std::cout << "\t[" << i << "] ";
		if (this->_inv[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inv[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

void	Character::_initInv(void)
{
	for (size_t i = 0; i < this->_invsize; i++)
		this->_inv[i] = NULL;
	return ;
}

void	Character::_removeInv(void)
{
	for (int i = 0; i < this->_invsize; i++)
	{
		if (this->_inv[i] != NULL)
		{
			delete this->_inv[i];
			this->_inv[i] = NULL;
		}
	}
	return ;
}
