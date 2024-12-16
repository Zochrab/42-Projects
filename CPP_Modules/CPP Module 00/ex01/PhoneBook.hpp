/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:14:22 by zblume            #+#    #+#             */
/*   Updated: 2024/12/16 08:32:42 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contact_count;
		int		oldest_index;

	public:
		PhoneBook();

		void addContact(const Contact &contact);
		void displayContacts() const;
		void displayContactDetails(int index) const;
};

#endif
