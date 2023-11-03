/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:09:39 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:09:39 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ATarget.hpp"

ATarget::ATarget(std::string const & type) : _type(type) {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

ATarget::~ATarget(){
    // std::cout << _name << ": My job here is done!" << std::endl;
};

std::string const   &ATarget::getType () const {
    return(_type);
}

void   ATarget::getHitBySpell(const ASpell & aspell)  const {
    std::cout << _type << " has been " << aspell.getEffects() << "!"<< std::endl;
}