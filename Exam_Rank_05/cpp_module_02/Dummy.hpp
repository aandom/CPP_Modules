/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:50:02 by aandom            #+#    #+#             */
/*   Updated: 2023/11/02 09:50:02 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        ~Dummy();
        Dummy(Dummy const & src);;
        Dummy &  operator=(Dummy const & src);
        
        ATarget * clone() const;

    private:

};


# endif