/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:44:39 by cde-migu          #+#    #+#             */
/*   Updated: 2025/08/06 15:35:20 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::newContact(void)
{
	Contact		*newContact;
	std::string	input[5];
	long		number;

	for (int i = 0; i < 5; ++i)
	{
		while (true)
		{
			if (i == 0)
				std::cout << "First name ---> ";
			else if (i == 1)
				std::cout << "Last name --> ";
			else if (i == 2)
				std::cout << "Nickname --> ";
			else if (i == 3)
				std::cout << "Phone Number --> ";
			else if (i == 4)
				std::cout << "Darkest secret --> ";
			if (!std::getline(std::cin, input[i]))
			{
				std::cout << "\nInput error." << std::endl;
				return ;
			}
			if (input[i].empty())
				std::cout << "Empty contact info" <<std::endl;
			if (i == 3 && !isValidNumber(input[i]))
				continue ;
			break ;
		}
	}
	number = atol(input[3].c_str());
	newContact = new Contact(input[0], input[1], input[2], number, input[4]);
	this->AddContact(*newContact);
	delete newContact;
}

void	PhoneBook::searchContact(void)
{
	std::string str;
	int			index;
	int			i;

	i = 0;
	if (numContact == 0)
	{
		std::cout << "There are no contacts :/ " << std::endl;
		return ;
	}
	while (i < numContact && i < 8)
	{
		contactList[i].printContactColumns(i);
		i++;
	}
	std::cout << "\t Select index: ";
	if (!std::getline(std::cin, str) || std::cin.eof())
    {
        std::cout << "\n \t No input or EOF detected" << std::endl;
        return;
    }
	std::cout << "el index escrito es --> " << str << std::endl;
	index = atoi(str.c_str());
	if (index > numContact || index < 1)
		std::cout << "\t \t select a valid index (1 to " << numContact << ")" << std::endl;
	else
		contactList[index - 1].printContactInfo();
}

