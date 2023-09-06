/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:30:00 by aandom            #+#    #+#             */
/*   Updated: 2023/08/20 00:30:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av){
    int i;
    int j;

    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        i = 1;
        while (i < ac){
            j = 0;
            while(av[i][j]){
                std::cout << (char) toupper(av[i][j]);
                j++;
            }
            if ( i != ac - 1)
                std::cout << ' ';
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}