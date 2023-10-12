/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:54:22 by aandom            #+#    #+#             */
/*   Updated: 2023/10/10 20:54:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
// #include <cstdint>
#include <stdint.h>

struct Data
{
    std::string name;
    int         age;
};

uintptr_t    serialize( Data *data );
Data*   deserialize( uintptr_t data );

# endif 