#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        ~Fireball();
        Fireball(Fireball const & src);;
        Fireball &  operator=(Fireball const & src);
        
        ASpell * clone() const;

    private:

};

# endif 