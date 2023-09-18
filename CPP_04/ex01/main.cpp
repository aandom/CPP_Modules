/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:34:08 by aandom            #+#    #+#             */
/*   Updated: 2023/09/15 06:34:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    // const Animal* i = new Cat();
    delete j;//should not create a leak
    // delete i;

    return 0;
}

