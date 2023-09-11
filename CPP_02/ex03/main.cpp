/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 06:01:02 by aandom            #+#    #+#             */
/*   Updated: 2023/09/10 06:01:02 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#define RED	"\e[31m"

bool bsp( Point const a, Point const b, Point const c, Point const p );


void	printIsPointInsideTriangle(Point const a, Point const b, Point const c, Point const p, bool expected )
{
	std::cerr << YELLOW "-- Triangle: A(" << a.get_x() << ", " << a.get_y() << ") "
		<< "B(" << b.get_x() << ", " << b.get_y() << ") "
		<< "C(" << c.get_x() << ", " << c.get_y() << ")" << std::endl
		<< "-- Point: P(" << p.get_x() << ", " << p.get_y() << ")" RESET << std::endl;
	std::cout << "Is point P inside triangle ABC? ";
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN "YES!" RESET;
	else
		std::cout << RED "NO." RESET;
	std::cout << " (Expected: ";
	if (expected == true)
		std::cout << GREEN "YES" RESET;
	else
		std::cout << RED "NO" RESET;
	std::cout << ")" << std::endl << std::endl;
	return ;
}

void	testSimpleTriangle( void )
{
	bool		expect;
	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(0, 6);

	std::cout << std::endl << "--- Simple triangle test" << std::endl << std::endl;
	{
		Point const p(0.0f, 5.0f);
		expect = true;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(a);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(10.0f, 1.5f);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(4.5f, 0.5f);
		expect = true;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	return ;
}

void	testFloatPointTriangle( void )
{
	bool		expect;
	Point const a(-5.44f, 0.29f);
	Point const b(2.62f, 2.95f);
	Point const c(1.0f, -1.45f);

	std::cout << std::endl << "--- Floating point triangle test" << std::endl << std::endl;
	{
		Point const p;
		expect = true;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(c);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(-5.45f, 0.29f);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	{
		Point const p(3.5f, 1.5f);
		expect = false;
		printIsPointInsideTriangle(a, b, c, p, expect);
	}
	return ;
}

int	main( void )
{
	testSimpleTriangle();
	testFloatPointTriangle();
	return ( 0 );
}