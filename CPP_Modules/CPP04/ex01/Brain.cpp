/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:47 by zblume            #+#    #+#             */
/*   Updated: 2025/06/04 11:44:53 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	int i;
	i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
}

Brain &Brain::operator=(const Brain &other)
{
	int i;
	
	i = 0;
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		while (i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}
