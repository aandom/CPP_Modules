/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:57:49 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 11:57:49 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    int N = 8;
    Zombie *arrayOfZombies = zombieHorde(N, "");

    for (int i = 0; i < N; i++) {
        arrayOfZombies[i].announce();
    }
    delete [] arrayOfZombies;
    return 0;
}