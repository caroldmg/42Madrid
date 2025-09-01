#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << "🐛🪲 Mensaje de-bug 🐛🪲" << std::endl;
	Harl::info();
}

void	Harl::info()
{
	std::cout << "ℹ️ Mensaje de info ℹ️" << std::endl;
	Harl::warning();
}

void	Harl::warning()
{
	std::cout << "🚨📢🔔⚠️ MENSAJE DE WARNING 🚨📢🔔⚠️" << std::endl;
	Harl::error();
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
			std::cout << "[" << level << "]" << std::endl;
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
