#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon construtor " << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "se ha creado WEAPON de type --> " << this->type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor " << std::endl;
}

std::string Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
