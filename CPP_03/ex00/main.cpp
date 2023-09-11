/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:48:14 by aandom            #+#    #+#             */
/*   Updated: 2023/09/11 08:48:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

    ClapTrap    clap1("clap1");
    ClapTrap    clap2("clap2");

    std::cout << clap1.getDamageP() << std::endl;
    std::cout << clap1.getEnergyP() << std::endl;
    std::cout << clap1.getHitP() << std::endl;
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.attack("clap2");
    clap1.takeDamage(7);
    // clap1.beRepaired(20);
    std::cout << clap1.getDamageP() << std::endl;
    std::cout << clap1.getEnergyP() << std::endl;
    std::cout << clap1.getHitP() << std::endl;
    clap1.takeDamage(7);
    std::cout << clap1.getDamageP() << std::endl;
    std::cout << clap1.getEnergyP() << std::endl;
    std::cout << clap1.getHitP() << std::endl;
    clap1.beRepaired(1);
    clap1.takeDamage(7);

    
}