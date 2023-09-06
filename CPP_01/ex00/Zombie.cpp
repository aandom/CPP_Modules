/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:34:34 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 09:34:34 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void)
{
    std::cout << "default constructor for Zombie" << std::endl;
    return ;
}

Zombie::Zombie (std::string name) : zname(name)
{
    std::cout << "A Constructor for a Zombie with name " << this->get_name() << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "A Destructor for a Zombie with name " << this->get_name() << std::endl;
    return ; 
}

std::string Zombie::get_name(void) const {
    return (this->zname);
}

void    Zombie::announce(void) {
    std::cout << this->get_name() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
