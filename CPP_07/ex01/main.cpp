/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:28:42 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 14:28:42 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void )
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: " << std::endl;
    iter(arr1, 5, &printelement);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\narr2: " << std::endl;
    iter(arr2, 5, &printelement);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: " << std::endl;
    iter(arr3, 5, &printelement);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: " << std::endl;
    iter(arr4, 5, &printelement);

    return 0;
}