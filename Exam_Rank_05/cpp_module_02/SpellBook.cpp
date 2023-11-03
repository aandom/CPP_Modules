# include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    // std::cout << _name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
};

void	SpellBook::learnSpell(ASpell * src)
{
	if (!src)
	{
		return ;
	}

	// if (_spells.find(m->getName())  == _spells.end())
	// 	_spells[m->getName()] = m->clone();
	_spells.insert(std::pair<std::string, ASpell *>(src->getName(), src->clone()));
	return ;
}


void	SpellBook::forgetSpell(std::string const & sname)
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

ASpell *	SpellBook::createSpell(std::string const & sname)
{
	std::map<std::string, ASpell *>::iterator it = _spells.find(sname);
	if (it != _spells.end()) {
		return (_spells[sname]);
	}
    return (NULL);

    // _spells.insert(std::pair<std::string, ASpell *>(sname, ->clone()));

	// if (_spells.find(sname)  != _spells.end())
	// 	_spells[sname]->launch(tar);
	// return ;
}