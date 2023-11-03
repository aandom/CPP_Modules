/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:50:05 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:50:05 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

Dummy::Dummy(Dummy const & src) : ATarget(src.getType()) {
    *this = src;
    return ;
}

Dummy & Dummy::operator=(Dummy const & src) {
    this->_type = src.getType();
	return (*this);
}

Dummy::~Dummy() {
    // std::cout << _name << ": My job here is done!" << std::endl;
};

ATarget * Dummy::clone() const {
    ATarget * res = new Dummy();
    return (res);
}
