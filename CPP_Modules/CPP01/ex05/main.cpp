/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:49:15 by zblume            #+#    #+#             */
/*   Updated: 2025/04/14 10:56:57 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::cout << "DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO level:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING level:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "Unknown level:" << std::endl;
	harl.complain("gwg");

	return (0);
}
