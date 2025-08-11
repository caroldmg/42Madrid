/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:08:25 by cde-migu          #+#    #+#             */
/*   Updated: 2025/08/06 15:22:12 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void	Contact::printColumn(std::string str)
{
	if (str.length() > 10)
		str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str << "|";
}

bool	isValidNumber(std::string phone)
{
	int i;
	
	i = 0;
	if (strlen(phone.c_str()) != 9)
	{
		std::cout << "Phone numbers must be 9 digits long" << std::endl;
		return (false);
	}
	while (phone[i])
	{
		if (std::isdigit(phone[i]) == false)
		{
			std::cout << "Wrong phone number: it should only have digits on it" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

void	checkInput(PhoneBook *phoneBook)
{
	std::string index;
	std::string	input;

	while (1)
	{
		std::cout << "Enter an action:  (ADD, SEARCH, EXIT) " << std::endl;
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			phoneBook->newContact();
		else if (input == "SEARCH")
			phoneBook->searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "acción no válida" << std::endl;
	}
	// llamar a esta funcion desde main, primero crear el phonebook, luego eliminarlo
}