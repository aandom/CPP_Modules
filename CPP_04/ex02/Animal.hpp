/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:23:14 by aandom            #+#    #+#             */
/*   Updated: 2023/09/14 07:23:14 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

#define RESET "\e[0m"
#define YELLOW "\e[33m"


class Animal
{
    public:
        Animal(void);
        // Animal (std::string const type);
        Animal (Animal const & src);
        virtual ~Animal();

        Animal & operator=(Animal const & src);
        std::string const &	getType(void) const;

        virtual void    makeSound(void) const = 0;

        
    protected:
        std::string _type;
};

# endif