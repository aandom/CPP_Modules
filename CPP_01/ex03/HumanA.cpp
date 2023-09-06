/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:13:37 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 18:13:37 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string ha_name, Weapon &ha_weapon) : hname(ha_name), weapon(ha_weapon) {
}

HumanA::~HumanA (){
}

void    HumanA::attack( void ) const {
    if (this->weapon.getType() != "") {
        std::cout << hname << " attacks with their weapon type " << this->weapon.getType() << std::endl;
    } else {
        std::cout << hname << " doesn't have a weapon to attack." << std::endl;
    }
}