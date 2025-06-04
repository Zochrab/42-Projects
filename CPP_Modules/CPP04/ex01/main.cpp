/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:38:08 by zblume            #+#    #+#             */
/*   Updated: 2025/06/04 11:27:16 by zblume           ###   ########.fr       */
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
	const int	numAnimals = 2;
    Animal**	animals = new Animal*[numAnimals];
	int			i;

	i = 0;
    while (i < numAnimals)
	{
        if (i < numAnimals / 2)
            animals[i] = new Dog();
		else
            animals[i] = new Cat();
		i++;
    }
	std::cout << std::endl;
	i = 0;
    while (i < numAnimals)
	{
        delete animals[i];
		i++;
	}

	delete[] animals;
	std::cout << std::endl;
	Dog dog;
	Cat cat;

	Dog dogCopy(dog);
	Cat catCopy(cat);
	return (0);
}
