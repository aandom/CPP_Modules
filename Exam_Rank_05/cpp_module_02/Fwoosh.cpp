/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:27:36 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:27:36 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fwoosh.hpp"


Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

Fwoosh::Fwoosh(Fwoosh const & src) : ASpell(src.getName(), src.getEffects()) {
    *this = src;
    return ;
}

Fwoosh & Fwoosh::operator=(Fwoosh const & src) {
    this->_name = src.getName();
    this->_effects = src.getEffects();
	return (*this);
}

Fwoosh::~Fwoosh() {
    // std::cout << _name << ": My job here is done!" << std::endl;
};

ASpell * Fwoosh::clone() const {
    ASpell * res = new Fwoosh();
    return (res);
}
