/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:27:40 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:27:40 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        Fwoosh(Fwoosh const & src);;
        Fwoosh &  operator=(Fwoosh const & src);
        
        ASpell * clone() const;

    private:

};

# endif 