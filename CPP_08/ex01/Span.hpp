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

# include <list>
# include <vector>
# include <string>
# include <numeric>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <sstream>
# include <string>
# include <climits>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\e[36m"


class Span
{
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span();

        Span & operator=(Span const & src);

        const std::list<int> & getArray() const;

        void            addNumber(int n);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;

        void            addNumber(std::list<int>::const_iterator itbegin, std::list<int>::const_iterator itend);

    private:
        Span();
        unsigned int _arrsize;
        std::list<int> _array;
};

std::ostream &	operator<<(std::ostream &os, Span const &obj);
std::ostream &	operator<<(std::ostream &os, std::list<int> &obj);
# endif