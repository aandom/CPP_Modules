/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 06:07:36 by aandom            #+#    #+#             */
/*   Updated: 2023/09/10 06:07:36 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point(void);
        Point( float const x, float const y);
        Point( Point const & src );
        ~Point();
        Point & operator=( Point const & src );

        Fixed const & get_y(void) const;
        Fixed const & get_x(void) const;
        
    private:
        Fixed const _x;
        Fixed const _y;
};

# endif