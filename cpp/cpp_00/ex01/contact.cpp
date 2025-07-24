/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:25:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/24 12:23:41 by cde-migu         ###   ########.fr       */
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

void	Contact::printContact(int i)
{
	printColumn(std::to_string(i + 1));
	std::cout << "|";
	printColumn(this->firstName);
	std::cout << "|";
	printColumn(this->lastName);
	std::cout << "|";
	printColumn(this->nickname);
	std::cout << std::endl;
}
