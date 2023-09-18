/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:33:41 by aandom            #+#    #+#             */
/*   Updated: 2023/09/16 21:33:41 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>


class Brain
{
    public:
        Brain(void);
        Brain(Brain const & src);
        ~Brain();

        Brain & operator=(Brain const & src);

        std::string const & getIdea(int idx) const; 
        void        setIdea(int idx, std::string const & idea);

    protected:
        std::string ideas[100];
};


# endif