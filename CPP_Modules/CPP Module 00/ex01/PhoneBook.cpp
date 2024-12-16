/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:23:31 by zblume            #+#    #+#             */
/*   Updated: 2024/12/16 10:01:35 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(): contact_count(0), oldest_index(0){}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[oldest_index] = contact;
	oldest_index = (oldest_index + 1) % 8;
	if (contact_count < 8)
		contact_count++;
	Contact newContact;
	
		
}

void PhoneBook::displayContacts() const
{
	int	i;

	std::cout <<  std::endl;
	std::cout << "\033[0;36m|     Index|First Name| Last Name|  Nickname|\033[0m" << std::endl;
	std::cout << "\033[0;36m|----------|----------|----------|----------|\033[0m" << std::endl;
	i = 0;
	while (i < contact_count)
	{
		std::cout << "\033[0;36m|\033[0m";
		std::cout << std::setw(10) << i;
		std::cout << "\033[0;36m|\033[0m";
		if (contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getFirstName().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName();
		std::cout << "\033[0;36m|\033[0m";
		if (contacts[i].getLastName().length() > 10)
			std::cout << std::setw(10) << contacts[i].getLastName().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getLastName();
		std::cout << "\033[0;36m|\033[0m";
		if (contacts[i].getNickname().length() > 10)
			std::cout << std::setw(10) << contacts[i].getNickname().substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].getNickname();
		std::cout << "\033[0;36m|\033[0m" << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index < 0 || index >= contact_count)
	{
		std::cout << "\033[31mError: Invalid index!\033[0m" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
