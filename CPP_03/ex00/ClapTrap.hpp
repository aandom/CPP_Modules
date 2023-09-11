/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:48:11 by aandom            #+#    #+#             */
/*   Updated: 2023/09/11 08:48:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);

        ClapTrap & operator=(ClapTrap const & src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void) const;
        unsigned int    getHitP(void) const;
        unsigned int    getEnergyP(void) const;
        unsigned int    getDamageP(void) const;

        static unsigned int const	defaultHitP = 10;
		static unsigned int const	defaultEnergyP = 10;
		static unsigned int const	defaultAttackDamage = 0;

    private:
        std::string     _name;
        unsigned int    _hit;
        unsigned int    _energy;
        unsigned int    _damage;
};


# endif