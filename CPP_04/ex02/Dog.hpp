/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:10:01 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:10:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

#define RESET "\e[0m"
#define GREEN "\e[32m"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const & src);
        ~Dog(void);

        Dog & operator=(Dog const & src);
        
        void    makeSound(void) const;
        Brain * getBrain(void) const;
        
    private:
        Brain * _brain;
};

# endif