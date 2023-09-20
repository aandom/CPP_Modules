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

# include "WrongAnimal.hpp"
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Cat();
    const Animal* n = new Dog();
    const WrongAnimal d;
    const WrongAnimal* i = new WrongCat();
    WrongCat    wcat;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Animal->getType()     : " << meta->getType() << std::endl;
    std::cout << "Cat->getType()        : " << j->getType()  << std::endl;
    std::cout << "Dog->getType()        : " << n->getType() << std::endl;
    std::cout << "Animal->makeSound()   : ";
    meta->makeSound();
    std::cout << "Cat->makeSound()      : ";
    j->makeSound();
    std::cout << "Dog->makeSound()      : ";
    n->makeSound();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "WrongAnimal->getType()                 : " << d.getType() << std::endl;
    std::cout << "WrongCat->getType() as WrongAnimal     : " << i->getType() << std::endl;
    std::cout << "WrongCat->getType() as WrongCat        : " << wcat.getType() << std::endl;
    std::cout << "WrongAnimal->makeSound()               : ";
    d.makeSound();
    std::cout << "WrongCat->makeSound()  as WrongAnimal  : ";
    i->makeSound();
    std::cout << "WrongCat->makeSound()  as WrongCat     : ";
    wcat.makeSound();
    std::cout << std::endl;
    std::cout << std::endl;

    delete meta;
    delete j;
    delete n;
    delete i;


    return 0;
}
