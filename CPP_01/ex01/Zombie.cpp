/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:34:01 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 11:34:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) {
}

Zombie::~Zombie(void) {
    std::cout << "A Destructor for a Zombie with name " << this->zname << std::endl;
    return ; 
}

void    Zombie::set_name(std::string name) {
    this->zname = name;
}

void    Zombie::announce(void) {
    std::cout << this->zname << " : BraiiiiiiinnnzzzZ..." << std::endl;
}