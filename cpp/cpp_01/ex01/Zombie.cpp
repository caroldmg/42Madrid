#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

Zombie::~Zombie()
{}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}