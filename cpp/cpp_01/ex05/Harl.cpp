#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "se ha creado un Harl" << std::endl;
}

Harl::~Harl()
{
	std::cout << "se ha eliminado un Harl" << std::endl;
}

void	Harl::debug()
{
	std::cout << "🐛🪲 Mensaje de-bug 🐛🪲" << std::endl;
}

void	Harl::info()
{
	std::cout << "ℹ️ Mensaje de info ℹ️" << std::endl;
}

void	Harl::warning()
{
	std::cout << "🚨📢🔔⚠️ MENSAJE DE WARNING 🚨📢🔔⚠️" << std::endl;
}

void	Harl::error()
{
	std::cout << "✋🏻🛑⛔️ MenSAje dE eRroR ✋🏻🛑⛔️" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "No es un valor válido. Prueba con: DEBUG, INFO, WARNING o ERROR" << std::endl;
}
