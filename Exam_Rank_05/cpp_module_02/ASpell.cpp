/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:59:47 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 08:59:47 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ASpell.hpp"

ASpell::ASpell(std::string const & name, std::string const & effects) : _name(name), _effects(effects) {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

ASpell::~ASpell(){
    // std::cout << _name << ": My job here is done!" << std::endl;
};

std::string const   &ASpell::getName () const {
    return(_name);
}

std::string const   &ASpell::getEffects () const {
    return(_effects);
}

void    ASpell::launch(ATarget const & atarget) const {
    atarget.getHitBySpell(*this);
}

