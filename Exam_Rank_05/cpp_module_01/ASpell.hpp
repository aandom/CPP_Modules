/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:00:10 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:00:10 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
    public:
        ASpell( std::string const & name , std::string const & effects);
        virtual ~ASpell();

         std::string const   &getName () const ;
         std::string const   &getEffects () const ;

         void   launch(ATarget & atarget) const;

         virtual ASpell* clone() const = 0;


    protected:
        std::string _name;
        std::string _effects;

        ASpell(ASpell const & src);;
        ASpell &  operator=(ASpell const & src);
        ASpell();
};


# endif