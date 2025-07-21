/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:48:54 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/21 17:19:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	newContact(PhoneBook *phoneBook)
{
	int			i;
	Contact		*newContact;
	std::string	input[5];
	long		number;

	i = 0;
	while (input[i] == "")
	{
		if (i == 0)
			std::cout << "First name ---> ";
		else if (i == 1)
			std::cout << "Last name --> ";
		else if (i == 2)
			std::cout << "Nickname --> ";
		else if (i == 3)
		{
			std::cout << "Phone Number --> ";
			if (isValidNumber(input[i]) == true)
				number = atol(input[i].c_str());
		}
		else if (i == 4)
			std::cout << "Darkest secret --> ";
		if (!std::getline(std::cin, input[i]))
			return ;
		i++;
	}
	newContact = new Contact(input[0], input[1], input[2], number, input[4]);
	
}

void	PhoneBook:: AddContact(Contact newContact)
{
	Contact aux;
	
	for (int i = 0; i < 8; i++)
	{
		// lo que quiero es que e contacto nuevo se añada al final del todo, asi que quiero mirar la cantidad de contactos qu etengo para meterlo al final, o eliminar el primero, subir los demás y poner el mío nuevo el último.
	}
}