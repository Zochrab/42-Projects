/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:40:09 by zblume            #+#    #+#             */
/*   Updated: 2025/04/09 10:31:17 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int			N;
	std::string name;
	int			i;

	name = "Zombie";
	N = 5;
	Zombie* horde = zombieHorde(N, name);
	i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return (0);
}
