/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:43:52 by aandom            #+#    #+#             */
/*   Updated: 2023/09/14 13:43:52 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

#define RESET "\e[0m"
#define BLUE "\e[34m"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const & src);
        ~Cat(void);

        Cat & operator=(Cat const & src);
        
        void    makeSound(void) const;
        Brain * getBrain(void) const;

    private:
        Brain * _brain;
};

# endif