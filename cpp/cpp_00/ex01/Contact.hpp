/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:14:55 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/24 12:23:58 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <iomanip>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		long	phoneNumber;
		std::string	darkSecret;
	public:
		Contact(std::string first, std::string last, std::string nick, long num, std::string secret);
		Contact();
		~Contact();

		Contact getContact();
		void	printContact(int i);
		void	printAllContacts();
		void	printColumn(std::string str);
};

// bool	isValidNumber(char *phone);
bool	isValidNumber(std::string phone);