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

int main( void )
{
    Data *data = new Data;

    data->name = "achraf hakimi";
    data->age = 30;

    uintptr_t deserialized = serialize(data);

    // std::cout << "Name: " << deserialize( serialize( data ) )->name << std::endl;
    // std::cout << "Age: " << deserialize( serialize( data ) )->age << std::endl;

    std::cout << "Name: " << deserialize(deserialized)->name << std::endl;
    std::cout << "Age: " << deserialize(deserialized)->age << std::endl;

    delete data;

    return (0);
}