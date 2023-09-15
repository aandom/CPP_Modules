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

bool bsp( Point const a, Point const b, Point const c, Point const point);


int	main( void )
{
	Point const a(0, 0);
	Point const b(0, 9);
	Point const c(8, 0);
	Point const p(1.0f, 5.0f);

	std::cout << "point A (" << a.get_x() << ", " << a.get_y() << ")" << std::endl;
	std::cout << "point B (" << b.get_x() << ", " << b.get_y() << ")" << std::endl;
	std::cout << "point C (" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
	std::cout << "point P (" << p.get_x() << ", " << p.get_y() << ")" << std::endl;
	std::cout << "Is point P inside triangle ABC : " << std::boolalpha  << bsp(a, b, c, p) << std::endl;
	std::cout<<std::endl;

	Point const e(0, 0);
	Point const f(0, 3);
	Point const g(8, 0);
	Point const m(0.0f, 2.0f);

	std::cout << "point E (" << e.get_x() << ", " << e.get_y() << ")" << std::endl;
	std::cout << "point F (" << f.get_x() << ", " << f.get_y() << ")" << std::endl;
	std::cout << "point G (" << g.get_x() << ", " << g.get_y() << ")" << std::endl;
	std::cout << "point M (" << m.get_x() << ", " << m.get_y() << ")" << std::endl;
	std::cout << "Is point M inside triangle EFG : " << std::boolalpha  << bsp(e, f, g, m) << std::endl;
	return ( 0 );
}