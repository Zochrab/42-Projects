/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:33:18 by zblume            #+#    #+#             */
/*   Updated: 2025/06/04 11:15:50 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
		
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		void makeSound() const;
};

#endif
