/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:21:15 by zblume            #+#    #+#             */
/*   Updated: 2025/06/03 11:57:18 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTraps more sophisticated constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTraps better functioning destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (_hitPoints <= 0)
			std::cout << "ScavTrap " << _name << " can't attack, it's already dead!" << std::endl;
		else if (_energyPoints <= 0)
			std::cout << "ScavTrap " << _name << " can't attack, it's out of energy!" << std::endl;
		else
			std::cout << "ScavTrap " << _name << " can't attack, for some reason!" << std::endl;	
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
}
