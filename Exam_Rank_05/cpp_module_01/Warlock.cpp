/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:05:05 by aandom            #+#    #+#             */
/*   Updated: 2023/11/01 11:05:05 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title) {
    std::cout << _name << ": This looks like another boring day." << std::endl;
    // this->_initWarlock();
}



// Warlock::Warlock(Warlock const & obj)
// {
// 	this->_name = obj.getName();
// 	this->_title = obj.getTitle();
// 	*this = obj;
// }


Warlock::~Warlock(){
    std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
    // this->_removeWarlock();
};

std::string const   &Warlock::getName () const {
    return(_name);
}

std::string const   &Warlock::getTitle () const {
    return(_title);
}


void   Warlock::setTitle (std::string const & title ) {
    this->_title = title;
}


void Warlock::introduce() const {
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell * m)
{
	if (!m)
	{
		return ;
	}

	// if (_spells.find(m->getName())  == _spells.end())
	// 	_spells[m->getName()] = m->clone();
	_spells.insert(std::pair<std::string, ASpell *>(m->getName(), m->clone()));
	return ;
}

void	Warlock::forgetSpell(std::string sname)
{
	std::map<std::string, ASpell *>::iterator it = _spells.find(sname);
	if (it != _spells.end()) {
		delete it->second;
	}
	_spells.erase(sname);

	// if (_spells.find(sname)  != _spells.end())
	// 	_spells.erase(_spells.find(sname));
	// return ;
}

void	Warlock::launchSpell(std::string sname, ATarget & tar)
{
	std::map<std::string, ASpell *>::iterator it = _spells.find(sname);
	if (it != _spells.end()) {
		_spells[sname]->launch(tar);
	}

	// if (_spells.find(sname)  != _spells.end())
	// 	_spells[sname]->launch(tar);
	// return ;
}

// void	Warlock::_initWarlock(void)
// {
// 	for (int i = 0; i < 100; i++)
// 		this->_spells[i] = NULL;
// 	return ;
// }


// void	Warlock::_removeWarlock(void)
// {
// 	for (int i = 0; i < 100; i++)
// 	{
// 		if (this->_spells[i] != NULL)
// 		{
// 			delete this->_spells[i];
// 			this->_spells[i] = NULL;
// 		}
// 	}
// 	return ;
// }
