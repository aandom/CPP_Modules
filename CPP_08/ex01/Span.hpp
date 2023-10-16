/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:33:36 by aandom            #+#    #+#             */
/*   Updated: 2023/10/16 12:33:36 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>

class Span
{
    public:
        Span(unsinged int n);
        Span & Span(Span const & src);
        ~Span();

    private:
        Span();
        unsigned int _n;
};

# endif