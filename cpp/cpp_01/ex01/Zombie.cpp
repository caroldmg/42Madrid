#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
	std::cout << "Zombie Constructor " << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor " << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}