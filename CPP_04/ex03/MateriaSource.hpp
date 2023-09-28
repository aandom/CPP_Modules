/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:23:58 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 13:23:58 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);
		MateriaSource & operator=(MateriaSource const & src);
	
		//IMateriaSource class implementation
		void		learnMateria(AMateria * m);
		AMateria *	createMateria(std::string const & type);

		//mem_functions
		void		dispmateriasource(void);

	private:
		static int const	_matsize = 4;
		AMateria *	_matsource[_matsize];
		void	_initMatSource(void);
		void	_removeMatSource(void);

};


# endif
