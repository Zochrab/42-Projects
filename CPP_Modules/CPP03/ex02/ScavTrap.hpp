/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:18:31 by zblume            #+#    #+#             */
/*   Updated: 2025/06/11 12:56:39 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &rhs);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif
