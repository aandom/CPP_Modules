/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:08:45 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 18:08:45 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string hname;
        Weapon     &weapon;

    public:
        HumanA(std::string ha_name, Weapon &ha_weapon);
        ~HumanA();
        void    attack(void) const;
};



# endif