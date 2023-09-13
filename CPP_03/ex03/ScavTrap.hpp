/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:18:21 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 02:18:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_DHP 100
# define SCAVTRAP_DEP 50
# define SCAVTRAP_DAD 20

class ScavTrap : virtual public ClapTrap
{
    public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & src);
		void	attack(std::string & target);
		void	guardGate(void);

    protected:
        ScavTrap(void);
};


# endif