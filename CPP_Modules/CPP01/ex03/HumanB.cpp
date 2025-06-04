/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:52:45 by zblume            #+#    #+#             */
/*   Updated: 2025/04/09 11:17:13 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const
{
    if (this->_weapon != NULL && this->_weapon->getType() != "")
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
        std::cout << _name << " attacks with their bare fists!" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
