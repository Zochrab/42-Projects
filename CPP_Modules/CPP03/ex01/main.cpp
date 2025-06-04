/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:02:01 by zblume            #+#    #+#             */
/*   Updated: 2025/06/03 11:53:02 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string> 

int main(void)
{
	ClapTrap	a("A");
	ScavTrap	s("S");
	
	a.attack(s.getName());
	s.takeDamage(a.getAttackDamage());
	s.beRepaired(5);
	s.attack(a.getName());
	a.takeDamage(s.getAttackDamage());
	s.guardGate();
	std::cout << a.getName() << " hitpoints: " << a.getHitPoints() << std::endl;
	std::cout << s.getName() << " hitpoints: " << s.getHitPoints() << std::endl;
	std::cout << s.getEnergyPoints() << std::endl;
	return (0);
}
