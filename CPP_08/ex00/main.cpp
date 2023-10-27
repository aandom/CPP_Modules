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

#include "easyfind.hpp"
#include <algorithm>

template <typename T>
void printElement(T& num) {
    std::cout << num << " ";
}

template <typename T>
void    tryfind(T& arr, int num) {
    std::cout << "Trying to find [ " << num << " ] in side [ "; 
    std::for_each(arr.begin(), arr.end(), printElement<int>);
    std::cout << "]" << std::endl;
    try
    {
        std::cout << *easyfind( arr, num) << std::endl;
        std::cout << "\tElement found\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"\t" << e.what() << '\n';
    }

}

int main(void) {

    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const char*                 arr1[] = {"hello", "42"};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    // std::for_each(vect.begin(), vect.end(), printElement<int>);
    // std::cout << std::endl;


    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );
    // std::for_each(list.begin(), list.end(), printElement<int>);
    // std::cout << std::endl;


    std::vector< std::string >      vect1( arr1, arr1 + sizeof( arr1 ) / sizeof( arr1[0] ) );
    // std::for_each(vect1.begin(), vect1.end(), printElement<std::string>);
    // std::cout << std::endl;

    tryfind(vect, 7);
    tryfind(list, 7);
    tryfind(vect, 90);

    // try
    // {
    //     std::cout << "Trying to find [ " << "42" << " ] in side [ ";
    //     std::for_each(vect1.begin(), vect1.end(), printElement<std::string>);
    //     std::cout << "]" << std::endl;
    //     std::cout << *easyfind( vect1, "42") << std::endl;
    //     std::cout << "Element found" << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    return (0);
}