/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:00:22 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 21:00:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const & src);
		void	 whoAmI();
		using	ScavTrap::attack;

    protected:
        DiamondTrap(void);
	
	private:
		std::string _name;
};

# endif