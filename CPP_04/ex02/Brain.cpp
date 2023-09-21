/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:38:00 by aandom            #+#    #+#             */
/*   Updated: 2023/09/16 21:38:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain default constructor called." << std::endl;
    return ;
}

Brain::Brain(Brain const & src) {
    std::cout << "Brain Copy constructor called." << std::endl;
    *this = src;
    return ;
}

Brain::~Brain(void) {
    std::cout << "Brain Destructor called." << std::endl;
    return ;
}

Brain & Brain::operator=(Brain const & src) {
    if (this != &src) {
        for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = src.ideas[i];
        }
    }
    std::cout << "Brain assignment overload operator called." << std::endl;
    return (*this);
}


std::string const & Brain::getIdea(int idx) const {
    if (idx < 0 || idx >= 100) {
        std::cout << "Invalid Index to Access" << std::endl;
        return (this->ideas[0]);
    }
    return (this->ideas[idx]);
}

void    Brain::setIdea(int idx, std::string const & idea) {
     if (idx < 0 || idx >= 100) {
        std::cout << "Invalid Index to Insert" << std::endl;
        return ;
     }
     this->ideas[idx] = idea;
     return ;

}



