/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:21:15 by zblume            #+#    #+#             */
/*   Updated: 2025/06/11 12:54:49 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTraps constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTraps copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTraps copy assignment operator called!" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTraps destructor called!" << std::endl;
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
