/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:54:25 by aandom            #+#    #+#             */
/*   Updated: 2023/10/10 20:54:25 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t    Serialization::serialize( Data *data ) {
    return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*   Serialization::deserialize( uintptr_t data ) {
    return ( reinterpret_cast< Data* >( data ) );
}