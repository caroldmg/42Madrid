/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:50:21 by cde-migu          #+#    #+#             */
/*   Updated: 2025/08/19 16:52:08 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
		std::cout << "-------------MAIN DE MIEDO---------------" << std::endl;
	std::cout << ">> Creamos zombies directamente en el main" << std::endl;
	Zombie *z1 = new Zombie("Pacozzz");
	Zombie *z2 = new Zombie("Aguzzztin");
	std::cout << ">> Despues los anunciamos" << std::endl;
	z1->announce();
	z2->announce();
	std::cout << ">> y los destruimos" << std::endl;
	z1->~Zombie();
	z2->~Zombie();
	std::cout << ">> Ahora hacemos uso de las funciones creadas a parte" << std::endl;
	std::cout << ">>> newZombie: " << std::endl;
	Zombie *z3 = NULL;
	z3 = newZombie("Juan Carlozzzzzzzz");
	z3->announce();
	std::cout << ">>> randomChump: " << std::endl;
	randomChump("Randomzzzzzzzzzz");
	std::cout << ">> delete;" << std::endl;
	delete z1;
	delete z2;
	delete z3;
	return 0;
}