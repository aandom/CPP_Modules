/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:20 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 16:02:20 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     std::cout << std::endl;

//     src->learnMateria(new Ice());
//     std::cout << std::endl;

//     src->learnMateria(new Cure());
//     std::cout << std::endl;

//     ICharacter* me = new Character("me");
//     std::cout << std::endl;

//     AMateria* tmp;
//     std::cout << std::endl;

//     tmp = src->createMateria("ice");
//     std::cout << std::endl;

//     me->equip(tmp);
//     std::cout << std::endl;

//     tmp = src->createMateria("cure");
//     std::cout << std::endl;

//     me->equip(tmp);
//     std::cout << std::endl;

//     ICharacter* bob = new Character("bob");
//     std::cout << std::endl;

//     me->use(0, *bob);
//     std::cout << std::endl;

//     me->use(1, *bob);
//     std::cout << std::endl;

//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }



// void	test_1(void)
// {
// 	std::cout << std::endl <<  "-------------------------------" << std::endl
// 		<< "\tMATERIA SOURCE TEST" << std::endl
// 		<<  "-------------------------------" << std::endl;
// 	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
// 	MateriaSource * source = new MateriaSource();
// 	source->dispmateriasource();

// 	// std::cout << std::endl << "-- LEARNING " << std::endl;
// 	// source->learnMateria(NULL);
// 	// source->learnMateria(new Cure());
// 	// source->learnMateria(new Ice());
// 	// source->dispmateriasource();

// 	// std::cout << std::endl << "-- MATERIA SOURCE DEEP COPY" << std::endl;
// 	// MateriaSource * copySource = new MateriaSource(*source);
// 	// std::cout << "Original MateriaSource ";
// 	// source->dispmateriasource();
// 	// std::cout << "Copy ";
// 	// copySource->dispmateriasource();
// 	// std::cout << "Original Materia Source learns another Materia" << std::endl;
// 	// source->learnMateria(new Cure());
// 	// std::cout << "Original ";
// 	// source->dispmateriasource();
// 	// std::cout << "Copy ";
// 	// copySource->dispmateriasource();
// 	// std::cout << "Deleting Copy Materia Source:" << std::endl;
// 	// delete copySource;


// 	std::cout << std::endl << "-- MATERIA SOURCE CREATING MATERIA FROM ITS SAVED MATERIA SOURCE" << std::endl;
// 	AMateria *	m1 = NULL;
// 	AMateria *	m2 = NULL;
// 	AMateria *	m3 = NULL;
	
// 	m1 = source->createMateria("ice");
// 	m2 = source->createMateria("cure");
// 	m3 = source->createMateria("rock");
// 	if (m1 != NULL)
// 		delete m1;
// 	if (m2 != NULL)
// 		delete m2;
// 	if (m2 != NULL)
// 		delete m3;

// 	std::cout << std::endl << "-- MATERIA SOURCE DELETION" << std::endl;
// 	delete source;
// }

int	main(void)
{
	// test_1();
	std::cout << std::endl << "\t-- CREATING MATERIA SOURCE" << std::endl;
	MateriaSource * matsource = new MateriaSource();
	matsource->learnMateria(new Cure());
	matsource->learnMateria(new Ice());
    matsource->dispmateriasource();

	std::cout << std::endl << "\t-- CREATING MATERIAS USING MATERIA SOURCE" << std::endl;
	AMateria * arrOfMateria[5];
	arrOfMateria[4] = NULL;

	for (int i = 0; i < 4; i++) {
		if (i % 2)
			arrOfMateria[i] = matsource->createMateria("ice");
		else
			arrOfMateria[i] = matsource->createMateria("cure");
	}
	std::cout << std::endl;

	std::cout << std::endl << "\t-- CREATING CHARACTERS ALICE AND BOB" << std::endl;
	// ICharacter * Alice = new Character("alice");
    Character * Alice = new Character("alice");
	Character *	Bob = new Character("bob");

	std::cout << std::endl << "\t-- EQUIPPING CHARACTERS" << std::endl;
	for (int i = 0; i < 4 / 2; i++)
		Alice->equip(arrOfMateria[i]);
	for (int i = 4 / 2; i < 4; i++)
		Bob->equip(arrOfMateria[i]);

    std::cout << std::endl;
    Alice->dispInv();
    std::cout << std::endl;
    Bob->dispInv();
    std::cout << std::endl;

	std::cout << std::endl << "\t-- ALICE AND BOB ARE FIGHTING USING THEIR MATERIAS" << std::endl;
	Alice->use(-1, *Alice);
	Alice->use(4, *Alice);
	Bob->use(3, *Alice);
	Alice->use(2, *Alice);
	Alice->use(1, *Bob);
	Bob->use(1, *Bob);
	Bob->use(2, *Alice);
	Bob->use(1, *Alice);
	Alice->use(0, *Bob);

	std::cout << std::endl << "\t-- DELETING CHARACTERS AND MATERIA SOURCE " << std::endl;
	delete Alice;
	delete Bob;

	std::cout << std::endl;
	delete matsource;
	return (0);
}