/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:52:35 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 10:52:35 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
        public:
            Ice(void);
            Ice(Ice const & src);
            ~Ice();

            Ice & operator=(Ice const & src);

            AMateria * clone() const;
            void        use(ICharacter & target);

};

# endif