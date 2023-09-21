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
    const Animal* i = new Cat();
    Cat * m = new Cat();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "cat_1->getIdea(0)     : " <<  m->getBrain()->getIdea(0) << std::endl;
    m->getBrain()->setIdea(0, "Cat is thinking about eating food");
    std::cout << "*Setting Cat_1 idea[0] [Cat is thinking]*" <<std::endl;
    std::cout << "cat_1->getIdea(0)     : " <<  m->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    Cat c = *m;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "cat_2->getIdea(0)     : " << c.getBrain()->getIdea(0) << std::endl;
    c.getBrain()->setIdea(0, "Cat is thinking about sleeping");
     std::cout << "*Setting Cat_2 idea[0] [Cat is thinking about sleeping]*" <<std::endl;
    std::cout << "cat_2->getIdea(0)     : " << c.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat_1->getIdea(0)     : " <<  m->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    delete j;//should not create a leak
    delete i;
    delete m;

    

    return 0;
}

