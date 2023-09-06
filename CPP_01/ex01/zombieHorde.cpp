/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:37:37 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 11:37:37 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    if (N <= 0)
        return (NULL);
    Zombie  *arrayOfZombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        arrayOfZombies[i].set_name(name);
    }
    return (arrayOfZombies);
}