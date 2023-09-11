/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:33 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 09:55:33 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string get_color(std::string const color, std::string const name) {
    std::string resColor (name);

    resColor.insert (0, color);
    resColor.append (DEFAULT);
    return (resColor);
}


int main(void) {
    std::string name;

    std::cout << "Creating zombie on the stack..........." << std::endl;
    Zombie zombiOnStack(get_color (YELLOW, "Zombie_1"));

    
    std::cout << "Creating zombie on the heap............" << std::endl;
    Zombie *zombiOnHeap = newZombie(get_color (CYAN," Zombie_2"));
    std::cout << "Calling announce for" <<  get_color (CYAN," Zombie_2") << std::endl;
    zombiOnHeap->announce();
    

    std::cout << "Calling randomChump()." << std::endl;
    randomChump(get_color(BLUE, "Random"));
    delete zombiOnHeap;
    return 0;
}
