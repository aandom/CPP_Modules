# include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {
    // std::cout << _name << ": This looks like another boring day." << std::endl;
}

BrickWall::BrickWall(BrickWall const & src) : ATarget(src.getType()) {
    *this = src;
    return ;
}

BrickWall & BrickWall::operator=(BrickWall const & src) {
    this->_type = src.getType();
	return (*this);
}

BrickWall::~BrickWall() {
    // std::cout << _name << ": My job here is done!" << std::endl;
};

ATarget * BrickWall::clone() const {
    ATarget * res = new BrickWall();
    return (res);
}
