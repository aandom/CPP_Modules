#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();
        Polymorph(Polymorph const & src);;
        Polymorph &  operator=(Polymorph const & src);
        
        ASpell * clone() const;

    private:

};

# endif 