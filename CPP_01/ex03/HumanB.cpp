/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:24:00 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 18:24:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string ha_name) : hname(ha_name), weapon(NULL) {
}

// HumanB::HumanB(std::string ha_name, Weapon &ha_weapon) : hname(ha_name), weapon(ha_weapon) {
// }

void    HumanB::setWeapon(Weapon &ha_weapon) {
    this->weapon = &ha_weapon;
}


HumanB::~HumanB (){
}
void    HumanB::attack( void ) const {
    if (this->weapon != NULL && this->weapon->getType() != "") {
        std::cout << hname << " attacks with their weapon type " << this->weapon->getType() << std::endl;
    } else {
        std::cout << hname << " doesn't have a weapon to attack." << std::endl;
    }
}