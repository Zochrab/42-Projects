/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:56:29 by zblume            #+#    #+#             */
/*   Updated: 2025/06/11 12:57:52 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap " << _name << " copy assigned." << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (_name);
}
int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}
int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}
int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::setName(const std::string& name)
{
	_name = name;
}
void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " can't attack, it's already dead!" << std::endl;
		else if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " can't attack, it's out of energy!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " can't attack, for some reason!" << std::endl;	
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't take any more damage, it's already dead!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	}
	else
	{
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " can't repair itself, it's already dead!" << std::endl;
		else if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " can't repair itself, it's out of energy!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " can't repair itself, for some reason!" << std::endl;
	}
}
