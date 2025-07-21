/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:08:25 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/21 13:08:52 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact:: printColumn(std::string str,  int len_str)
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

bool	Contact:: isValidNumber(char *phone)
{
	int i;
	
	i = 0;
	if (strlen(phone) != 9)
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
	this->phoneNumber = atol(phone);
	return (true);
}

