/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:43:14 by cde-migu          #+#    #+#             */
/*   Updated: 2025/08/11 12:58:47 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
	
		Zombie *newZombie(std::string name);
		/* This function creates a zombie, names it, and returns it so you can use it outside
of the function scope. */
		void	randomChump(std::string name);
		/* This function creates a zombie, names it, and makes it announce itself. */
		void	announce();
};
