/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:39 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/24 12:57:55 by cde-migu         ###   ########.fr       */
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
	phoneBook->AddContact(*newContact);
	delete newContact;
}

void	searchContact(PhoneBook *phoneBook)
{
	std::string str;
	
}

void	check_input(PhoneBook *phoneBook)
{
	int 		i;
	std::string index;
	std::string	input;

	while (1)
	{
		std::cout << "Introduzca una acción:  (ADD, SEARCH, EXIT) " << std::endl;
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			newContact(phoneBook);
		else if (input == "SEARCH")
			searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "acción no válida" << std::endl;
	}
	// llamar a esta funcion desde main, primero crear el phonebook, luego eliminarlo
}