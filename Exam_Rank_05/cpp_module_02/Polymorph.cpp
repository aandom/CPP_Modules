# include "Polymorph.hpp"


Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

Polymorph::Polymorph(Polymorph const & src) : ASpell(src.getName(), src.getEffects()) {
    *this = src;
    return ;
}

Polymorph & Polymorph::operator=(Polymorph const & src) {
    this->_name = src.getName();
    this->_effects = src.getEffects();
	return (*this);
}

Polymorph::~Polymorph() {
    // std::cout << _name << ": My job here is done!" << std::endl;
};

ASpell * Polymorph::clone() const {
    ASpell * res = new Polymorph();
    return (res);
}
