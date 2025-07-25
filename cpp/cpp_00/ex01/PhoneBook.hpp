/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:14:28 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/24 12:52:19 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
	public:
		int numContact;
		
		PhoneBook();
		~PhoneBook();

		void	AddContact(Contact newContact);
		Contact GetContact(int index);
};

void	newContact(PhoneBook *phoneBook);
void	checkInput(PhoneBook *phoneBook);