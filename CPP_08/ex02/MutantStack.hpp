/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:44:05 by aandom            #+#    #+#             */
/*   Updated: 2023/10/18 08:44:05 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <stack>
# include <iostream>
# include <list>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack (const MutantStack & src) : std::stack<T, Container>(src) {};

        MutantStack & operator=(const MutantStack & src) {
            std::stack< T, Container>::operator=(src);
            return (*this);
        }

        typedef typename Container::iterator    iterator;

        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }

    private:
        
}; 


# endif