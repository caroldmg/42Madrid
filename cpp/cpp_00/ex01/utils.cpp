/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:08:25 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/24 13:03:29 by cde-migu         ###   ########.fr       */
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
		if (std::isdigit((int)phone[i]) == false)
		{
			std::cout << "Wrong phone number: it should only have digits on it" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

void	displayAllContacts(PhoneBook phoneBook)
{
	int	i = 0,

	while (i < phoneBook.contactList.lenght()) //???? como hago esto???
}