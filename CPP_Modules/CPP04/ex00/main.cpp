/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:38:08 by zblume            #+#    #+#             */
/*   Updated: 2025/06/04 10:58:35 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal* w = new WrongCat();

	std::cout << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	d->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	std::cout << std::endl;
	delete (meta);
	delete (d);
	delete (c);
	delete (w);
	return (0);
}
