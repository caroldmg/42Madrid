#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << "se ha creado el HumanB con nombre " << this->name << std::endl;
}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout << this->name << " does not have a weapon :(" << std::endl;
	std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}