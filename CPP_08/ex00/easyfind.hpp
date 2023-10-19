/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:04:45 by aandom            #+#    #+#             */
/*   Updated: 2023/10/13 04:04:45 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator   easyfind(T& arr, int num) {

    typename T::iterator it;

    it = std::find(arr.begin(), arr.end(), num);
    if (it == arr.end())
        throw (std::out_of_range("Element Not found"));
    return (it);
}


// template <typename T, typename C>
// typename T::iterator   easyfind(T& arr, C& num) {

//     typename T::iterator it;
//     it = std::find(arr.begin(), arr.end(), num);
//     if (it == arr.end())
//         throw (std::out_of_range("Element Not found"));
//     return (it);
// }


# endif