#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{}

std::string Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
