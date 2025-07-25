/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:48:54 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/23 12:52:07 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	numContact = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor" << std::endl;
}

void	PhoneBook:: AddContact(Contact newContact)
{
	Contact aux;
	
	for (int i = 0; i < 8; i++)
	{
		aux = contactList[i];
		contactList[i] = newContact;
		newContact = aux;
	}
	if (numContact <= 8)
		numContact++;
}

Contact PhoneBook::GetContact(int index)
{
	return (contactList[index]);
}