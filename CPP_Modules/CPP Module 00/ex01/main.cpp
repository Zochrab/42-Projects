/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:40:12 by zblume            #+#    #+#             */
/*   Updated: 2024/12/16 10:14:12 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <cctype>
#include <iostream>

int	ft_stoi(std::string const &nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			n = n * 10 + (nptr[i] - '0');
		else
			return (-1);
		i++;
	}
	return (n * sign);
}

int main(void)
{
	PhoneBook phone_book;
	std::string command;
	while (1)
	{
		std::cout << "\033[0;36mEnter a command (\033[0;34mADD\033[0;36m, \033[0;34mSEARCH\033[0;36m, \033[0;34mEXIT\033[0;36m): \033[0m";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			Contact newConatct;
			std::string input;

			std::cout << "\033[0;34mEnter First Name: \033[0m";
			std::getline(std::cin, input);
			if (!input.empty())
				newConatct.setFirstName(input);
			else
			{
				std::cout << "\033[31mError: Contact Field is empty!\033[0m" << std::endl;
				continue ;
			}
			std::cout << "\033[0;34mEnter Last Name: \033[0m";
			std::getline(std::cin, input);
			if (!input.empty())
				newConatct.setLastName(input);
			else
			{
				std::cout << "\033[31mError: Contact Field is empty!\033[0m" << std::endl;
				continue ;
			}
			std::cout << "\033[0;34mEnter Nickname: \033[0m";
			std::getline(std::cin, input);
			if (!input.empty())
				newConatct.setNickname(input);
			else
			{
				std::cout << "\033[31mError: Contact Field is empty!\033[0m" << std::endl;
				continue ;
			}
			std::cout << "\033[0;34mEnter Phone Number: \033[0m";
			std::getline(std::cin, input);
			if (!input.empty())
				newConatct.setPhoneNumber(input);
			else
			{
				std::cout << "\033[31mError: Contact Field is empty!\033[0m" << std::endl;
				continue ;
			}
			std::cout << "\033[0;34mEnter Darkest Secret: \033[0m";
			std::getline(std::cin, input);
			if (!input.empty())
				newConatct.setDarkestSecret(input);
			else
			{
				std::cout << "\033[31mError: Contact Field is empty!\033[0m" << std::endl;
				continue ;
			}
			phone_book.addContact(newConatct);
			std::cout <<"\033[0;32mContact got succesfully added!\033[0m" << std::endl;
		}
		else if (command == "SEARCH")
		{
			int	i;
			i = -1;
			phone_book.displayContacts();
			std::cout << "\033[0;36mEnter The Index to display detailed View or enter anything else to return: \033[0m";
			std::getline(std::cin, command);
			if (isdigit(command[0]) && !command.empty())
			{
				i = ft_stoi(command);
				phone_book.displayContactDetails(i);
			}
			else
				std::cout << "\033[0;31mReturning to previous menu\033[0m" << std::endl;
		}
		else
			std::cout << "\033[0;31mError: Command not found!\033[0m" << std::endl;
	}
}
