/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:56:48 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 12:56:48 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string  const wtype) : type(wtype) {
}

Weapon::~Weapon() {
}

std::string const   &Weapon::getType(void) const {
    return (this->type);
}

void    Weapon::setType(std::string const wtype) {
    this->type = wtype;
}



