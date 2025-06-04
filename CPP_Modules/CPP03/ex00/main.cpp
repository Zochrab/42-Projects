/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:02:01 by zblume            #+#    #+#             */
/*   Updated: 2025/06/03 11:54:12 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/*
int main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	return (0);
}
*/

int main(void)
{
	ClapTrap	a("BorderLands");
	std::string b = "Beast";

	a.attack(b);
	a.takeDamage(5);
	a.beRepaired(5);

	a.setHitPoints(0);
	a.attack(b);
	a.setEnergyPoints(0);
	a.beRepaired(0);
	return (0);
}
