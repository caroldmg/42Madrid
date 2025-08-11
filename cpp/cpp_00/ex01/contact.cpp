/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:25:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/08/11 12:38:14 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first, std::string last, std::string nick, long num, std::string secret)
{
	std::cout << "Contact constructor" << std::endl;
	this->firstName = first;
	this->lastName = last;
	this->nickname = nick;
	this->phoneNumber = num;
	this->darkSecret = secret;
}

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->darkSecret = "";
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor" << std::endl;
}

void	Contact::printContactColumns(int i)
{
	std::stringstream index;

	index << (i + 1);
	printColumn(index.str());
	printColumn(this->firstName);
	printColumn(this->lastName);
	printColumn(this->nickname);
	std::cout << std::endl;
}

void	Contact:: printContactInfo(void)
{
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Dark secret: " << this->darkSecret << std::endl;
}