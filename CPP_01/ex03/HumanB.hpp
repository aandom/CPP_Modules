/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:24:25 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 18:24:25 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string hname;
        Weapon      *weapon;

    public:
        HumanB(std::string ha_name);
        // HumanB(std::string ha_name, Weapon &ha_weapon);
        ~HumanB();
        void    attack(void) const;
        void    setWeapon(Weapon &ha_weapon);
};



# endif