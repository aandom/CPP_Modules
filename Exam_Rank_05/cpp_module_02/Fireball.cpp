# include "Fireball.hpp"


Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

Fireball::Fireball(Fireball const & src) : ASpell(src.getName(), src.getEffects()) {
    *this = src;
    return ;
}

Fireball & Fireball::operator=(Fireball const & src) {
    this->_name = src.getName();
    this->_effects = src.getEffects();
	return (*this);
}

Fireball::~Fireball() {
    // std::cout << _name << ": My job here is done!" << std::endl;
};

ASpell * Fireball::clone() const {
    ASpell * res = new Fireball();
    return (res);
}
