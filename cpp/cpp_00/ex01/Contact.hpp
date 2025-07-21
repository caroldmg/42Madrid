/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:14:55 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/21 12:47:04 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <ctype.h>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		long	phoneNumber;
		std::string	darkSecret;
	public:
		Contact::Contact(std::string first, std::string last, std::string nick, long num, std::string secret);
		~Contact();
		
		void	printContact(int i);
		void	printAllContacts();
		void	print_col(std::string str,  int len_str);
};
