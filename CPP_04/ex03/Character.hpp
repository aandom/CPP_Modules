/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:01:13 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 11:01:13 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(Character  & src);
		Character(std::string const & name);
		~Character();
		Character & operator=(Character & src);

		// class ICharacter member functions 
		std::string const & getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		// new mem functions
		void				setName(std::string const & name);
		void				dispInv() const;

	private:
		static	int	const _invsize = 4;
		std::string	_name;
		AMateria *	_inv[_invsize];

		void	_initInv(void);
		void	_removeInv(void);


};


# endif