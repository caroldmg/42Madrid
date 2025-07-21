/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:14:28 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/21 17:10:52 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
• PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.
◦ Please note that dynamic allocation is forbidden.
 */

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
	public:
		int numContact;
		
		PhoneBook();
		~PhoneBook();
		
		void	newContact();
		void	AddContact(Contact newContact);
		Contact GetContact(int i);
}
		
