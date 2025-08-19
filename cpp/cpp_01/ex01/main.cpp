#include "Zombie.hpp"

int main(void)
{
	std::cout << ">> INICIAMOS HORDAAA" << std::endl;
	Zombie *horde = zombieHorde(7, "zzZZZacariazzzZZZz");
	std::cout << ">> ELIMINAMOS HORDAAA" << std::endl;
	delete[] horde;
	return (0);
}
