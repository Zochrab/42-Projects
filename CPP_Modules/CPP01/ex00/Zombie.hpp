/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:36:55 by zblume            #+#    #+#             */
/*   Updated: 2025/04/09 10:15:56 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
