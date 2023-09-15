/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:41:41 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 20:41:41 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main (int ac, char **av )
{
    if (ac != 4) {
        std::cerr << "Usage: ./repFile <filename> <to_find> <replace>." << std::endl;
        return 1;
    } else {
        Sed   sed(av[1]);
        if ( sed.replacestr(av[2], av[3]) == -1) {
            return (1);
        }
    }
    return 0;
}