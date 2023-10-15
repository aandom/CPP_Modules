/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:25:27 by aandom            #+#    #+#             */
/*   Updated: 2023/10/11 14:25:27 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T *array, size_t size, void (*f)(T const &))
{
    std::cout << "[ ";
    for (size_t i = 0; i < size; i++) {
        f(array[i]);
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

template <typename T>
void    printelement(T const &i)
{
    std::cout << i;
}

# endif