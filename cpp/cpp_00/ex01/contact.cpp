/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:25:24 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/21 12:47:48 by cde-migu         ###   ########.fr       */
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

Contact::~Contact()
{
	std::cout << "Contact destructor" << std::endl;
}

void Contact:: print_col(std::string str,  int len_str)
{
	int spaces;
	int j = 0;
	int i = 0;

	spaces = 10 - len_str;
	while (i < spaces)
	{
		std::cout << " ";
		i++;
	}
	while (j < 9 && j < len_str)
	{
		std::cout << str[j++];
	}
	if (len_str >= 10)
		std::cout << ".";
}

void	Contact::printContact(int i)
{
	print_col(std::to_string(i + 1), 1);
	std::cout << "|";
	print_col(this->firstName, firstName.length());
	std::cout << "|";
	print_col(this->lastName, lastName.length());
	std::cout << "|";
	print_col(this->nickname, nickname.length());
	std::cout << std::endl;
}

