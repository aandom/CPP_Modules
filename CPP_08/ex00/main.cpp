/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:12:42 by aandom            #+#    #+#             */
/*   Updated: 2023/10/13 05:12:42 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>

void printElement(int num) {
    std::cout << num << ' ';
}

int main(void)
{

    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::for_each(vect.begin(), vect.end(), printElement);
    std::cout << std::endl;
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::for_each(list.begin(), list.end(), printElement);
    std::cout << std::endl;


    easyfind( vect, 7);
    easyfind( list, 20);

    return (0);
}