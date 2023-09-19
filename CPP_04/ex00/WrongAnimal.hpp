/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:20:21 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:20:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

#define RESET "\e[0m"
#define CYAN "\e[36m"


class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal (std::string type);
        WrongAnimal (WrongAnimal const & src);
        ~WrongAnimal();

        WrongAnimal & operator=(WrongAnimal const & src);
        std::string const &	getType(void) const;

        void    makeSound(void) const;

        
    protected:
        std::string _type;
};

# endif