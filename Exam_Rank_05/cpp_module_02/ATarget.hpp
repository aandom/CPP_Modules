/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:09:55 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:09:55 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
    public:
        ATarget( std::string const & type);
        virtual ~ATarget();

         std::string const   &getType () const ;

         void getHitBySpell(const ASpell & aspell) const;
         
         virtual ATarget * clone() const = 0;



    protected:
        std::string _type;

        ATarget(ATarget const & src);;
        ATarget &  operator=(ATarget const & src);
        ATarget();
};


# endif