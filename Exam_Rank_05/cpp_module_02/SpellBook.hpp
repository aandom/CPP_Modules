#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <algorithm>
# include <map>

class ASpell;
class ATarget;

class SpellBook
{
    public:
        ~SpellBook();
        SpellBook();


        void learnSpell(ASpell * src);
        void forgetSpell(std::string const & sname);
        ASpell * createSpell(std::string const & sname);


    private:
        std::string _name;
        std::string _title;
        // ASpell * _spells[100];
        std::map<std::string, ASpell *> _spells;
        
        SpellBook &  operator=(SpellBook const & src);
        SpellBook(SpellBook const & src);


        void	_initSpellBook(void);
        void	_removeSpellBook(void);
};

# endif