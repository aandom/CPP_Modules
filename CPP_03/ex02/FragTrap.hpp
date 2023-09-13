/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:31:32 by aandom            #+#    #+#             */
/*   Updated: 2023/09/12 20:31:32 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_DHP 100
# define FRAGTRAP_DEP 100
# define FRAGTRAP_DAD 30

class FragTrap : public ClapTrap
{
    public:
		FragTrap(std::string & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & src);
		void	highFivesGuys(void);

    private:
        FragTrap(void);
};


# endif