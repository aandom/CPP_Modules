/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:51:01 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 02:51:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

#define	DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"

class Zombie
{
    private:
        std::string zname;
        std::string get_name (void) const;

    public:
        Zombie(void);
        Zombie (std::string name);
        ~Zombie();
        void    announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

# endif