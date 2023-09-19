/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:33:31 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 10:33:31 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
        public:
            Cure(void);
            Cure(Cure const & src);
            ~Cure();

            Cure & operator=(Cure const & src);

            AMateria * clone(void) const;
            void        use(ICharacter & target);

};



# endif