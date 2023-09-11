/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 06:52:00 by aandom            #+#    #+#             */
/*   Updated: 2023/09/11 06:52:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"
# include "Fixed.hpp"

Fixed   areaOfTriangle( Point const a, Point const b, Point const c) {

    Fixed area = ((a.get_x() * (b.get_y() - c.get_y())) 
               + (b.get_x() * (c.get_y() - a.get_y()))
               + (c.get_x() * (a.get_y() - b.get_y()))) / 2;
    Fixed   result = Fixed(abs(area.toFloat()));
    return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    
    Fixed   areaABC = areaOfTriangle(a, b , c);
    Fixed   areaPAB = areaOfTriangle(a, b, point);
    Fixed   areaPCB = areaOfTriangle(b , point, c);
    Fixed   areaPAC = areaOfTriangle(a, point, c);

    if (areaPAC != 0 && areaPAB != 0 && areaPCB != 0 &&
        areaPAB + areaPAC + areaPCB <= areaABC)
        return (true);
    return (false);
}