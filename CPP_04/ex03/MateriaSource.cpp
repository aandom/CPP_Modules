/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:17:01 by aandom            #+#    #+#             */
/*   Updated: 2023/09/19 13:17:01 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    std::cout << "MateriaSource default Constructor called." << std::endl;
    this->_initMatSource();
    return ;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    std::cout << "MateriaSource copy Constructor called." << std::endl;
    this->_initMatSource();
    *this = src;
    return ;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource Destructor called." << std::endl;
    this->_removeMatSource();
    return ;
}

MateriaSource   & MateriaSource::operator=(MateriaSource const & src) {

	std::cout << "MateriaSource assignment operator overload called." << std::endl;
	this->_removeMatSource();
	for (size_t i = 0; i < this->_matsize; i++)
	{
		if (src._matsource[i] != NULL)
			this->_matsource[i] = src._matsource[i]->clone();
	}
	return (*this);
}


void	MateriaSource::learnMateria(AMateria * m)
{
	if (!m)
	{
		std::cout << "MateriaSource was not provided with a materia to learn." << std::endl;
		return ;
	}
	for (int i = 0; i < this->_matsize; i++)
	{
		if (this->_matsource[i] == NULL)
		{
			this->_matsource[i] = m;
			std::cout << "MateriaSource learned the " << m->getType()
				<< " materia." << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource can't learn any more materia." << std::endl;
	delete m;
	return ;
}

AMateria *	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_matsize; i++)
	{
		if (this->_matsource[i]
			&& this->_matsource[i]->getType() == type)
		{
			std::cout << "MateriaSource creating " << type
				<< " materia."  << std::endl;
			return (this->_matsource[i]->clone());
		}
	}
	std::cout << "MateriaSource does not know the type \""
		<< type << "\"." << std::endl;
	return (NULL);
}

void	MateriaSource::_initMatSource(void)
{
	for (int i = 0; i < this->_matsize; i++)
		this->_matsource[i] = NULL;
	return ;
}

void	MateriaSource::_removeMatSource(void)
{
	for (int i = 0; i < this->_matsize; i++)
	{
		if (this->_matsource[i] != NULL)
		{
			delete this->_matsource[i];
			this->_matsource[i] = NULL;
		}
	}
	return ;
}

void	MateriaSource::dispmateriasource(void)
{
	std::cout << "MateriaSource knows the following recipes:" << std::endl;
	for (int i = 0; i < this->_matsize; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_matsource[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_matsource[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}
