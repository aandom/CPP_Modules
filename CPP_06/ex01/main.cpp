/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:05:05 by aandom            #+#    #+#             */
/*   Updated: 2023/10/10 21:05:05 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main( void )
{
    Data *data = new Data;

    data->name = "Alice";
    data->age = 30;

    uintptr_t serialized = Serialization::serialize(data);
    std::cout << "Before Serilization " << std::endl; 
    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Age: " << data->age << std::endl;

    std::cout << "After Serilization :  " << serialized << std::endl;

    // std::cout << "Name: " << deserialize(serialized)->name << std::endl;
    // std::cout << "Age: " << deserialize(serialized)->age << std::endl;

    Data * deserialized = Serialization::deserialize(serialized);

    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << data->age << std::endl;

    delete data;

    return (0);
}